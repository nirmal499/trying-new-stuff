package mod10.exercise2;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.concurrent.Flow;
import java.util.function.Supplier;
import java.util.stream.Stream;

public class Ex2 {
    public static void main(String[] args) {
        String pathString = System.getProperty("user.home") + "/javaTemp/nums.txt";
        Supplier<String> supplier = new Supplier<String>() {
            int index;

            /*
             * The Supplier, however, cannot return the entire dataset; it is designed to
             * return one string at a time. For this to work, we need to keep an index of
             * the last string sent to Supplier
             */
            @Override
            public String get() {
                String[] data = getStrings(pathString);
                if (index < data.length - 1) {
                    /*
                     * return data[index] => This will constantly return the first number in the
                     * file, and that's not what we want. So, we need to increment the index every
                     * time someone asks the supplier for a string:
                     */
                    return data[index++];
                } else {
                    /*
                     * This, however, will throw an exception when we reach the final number in the
                     * file. So, we need to protect against that. In this case, we'll return null
                     * when we reach
                     */
                    return null;
                }
            }
        };
        /*
         * This example shows how to take content from a publisher and pass it through a
         * processor to ensure that the values are valid.
         */

        NumberPublisher publisher = new NumberPublisher(supplier);
        /* publisher is getting closed in the class NumberPublisher */

        NumberProcessor processor = new NumberProcessor();

        publisher.subscribe(processor);

        processor.subscribe(new Flow.Subscriber<>() {
            Flow.Subscription subscription;

            @Override
            public void onSubscribe(Flow.Subscription subscription) {
                this.subscription = subscription;
                subscription.request(1);
            }

            @Override
            public void onNext(String item) {
                System.out.println("onNext: " + Integer.valueOf(item));
                subscription.request(1);
            }

            @Override
            public void onError(Throwable throwable) {
                System.out.println("onError: " + throwable.getMessage());
            }

            @Override
            public void onComplete() {
                System.out.println("onComplete()");
            }
        });

        // publisher.close();
    }

    private static String[] getStrings(String pathString) {
        try (Stream<String> words = Files.lines(Paths.get(pathString))) {
            /*
             * First of all, apply a flatMap operator to create a new stream for each item
             * in the original stream. This will let us split each line up into multiple
             * items, and return them to the main stream
             */
            return words.flatMap((line) -> Arrays.stream(line.split("[\\s\\n]+"))).peek((word) -> {
                // System.out.println(word);
            }).filter((word) -> word.length() > 0).toArray(String[]::new);
        } catch (IOException e) {
            e.printStackTrace();
        }
        /*
         * However, if we do have an error in reading the file, we need to return
         * something too. Return null at the very end of the getStrings() method. The
         * publisher will interpret null as an error and throw NullPointerException,
         * closing the connection to the subscriber:
         */
        return null;
    }
}
