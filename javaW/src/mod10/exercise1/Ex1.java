package mod10.exercise1;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.concurrent.SubmissionPublisher;
import java.util.stream.Stream;

public class Ex1 {
    public static void main(String[] args) {
        SubmissionPublisher<String> publisher = new SubmissionPublisher<>();

        LipsumSubscriber lipsumSubscriber = new LipsumSubscriber();

        publisher.subscribe(lipsumSubscriber);

        String pathString = System.getProperty("user.home") + "/javaTemp/lipsum.txt";

        /*
         * lipsum.txt : Lorem ipsum dolor sit amet, consectetur adipiscing elit.
         * Pellentesque malesuada ultricies ultricies. Curabitur non aliquam est.
         * Pellentesque elementum ornare erat sit amet convallis. Cras non pulvinar ...
         * 
         */

        /*
         * To send the words from the lipsum.txt file to the Publisher, you need to load
         * the file into some kind of container. We will use the Stream API to load the
         * words, and then push them to the publisher immediately. Wrap the stream in a
         * try-withresources block to enable the JVM to auto-close the resource after
         * loading it
         */
        try (Stream<String> words = Files.lines(Paths.get(pathString))) {
            /*
             * Here, we are loading the file as a stream of strings. It will load the lines
             * from the file into one string each. Since every line may contain multiple
             * words, we need to apply a flat mapping to each line to extract the words. We
             * are using a simple regular expression to split the lines into words, looking
             * for one or more whitespaces, punctuation items, or a new line
             */
            words.flatMap((l) -> Arrays.stream(l.split("[\\s.,\\n]+"))).forEach(publisher::submit);
            publisher.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
