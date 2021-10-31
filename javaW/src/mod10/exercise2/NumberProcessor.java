package mod10.exercise2;

import java.util.concurrent.Flow;
import java.util.concurrent.SubmissionPublisher;
import java.util.function.Predicate;

/*  Processor will subscribe to Publisher, and Subscriber will subscribe to
    Processor. In essence, Processor is both a Publisher and a Subscriber. To make
    this simple for us, allow NumberProcessor to extend SubmissionPublisher, just like
    NumberPublisher does 
*/
public class NumberProcessor extends SubmissionPublisher<String> implements Flow.Processor<String, String> {
    private Flow.Subscription subscription;

    private Predicate<String> predicate = new Predicate<String>() {
        @Override
        public boolean test(String s) {
            try {
                Integer.valueOf(s);
                return true;
            } catch (NumberFormatException e) {
                return false;
            }
        }
    };

    /*
     * NumberProcessor will subscribe to NumberPublisher, and, just like the
     * subscriber, it needs to store a reference to the publisher so that it can
     * control when to request new items. Store the reference received in
     * onSubscribe() as a private field in the processor. Also, take this
     * opportunity to request the first item from the publisher
     */
    @Override
    public void onSubscribe(Flow.Subscription subscription) {
        this.subscription = subscription;
        this.subscription.request(1);

    }

    /*
     * Whenever you receive an item from the publisher, you need to also request the
     * next item, just like the subscriber would
     */
    @Override
    public void onNext(String item) {
        /*
         * The processor is almost done. The one thing that is missing is communicating
         * the received items back to the subscriber. We will do this in the onNext()
         * callback method. However, since we know that there may be invalid values, we
         * want to filter those. We'll use a predicate for this, declaring a predicate
         * to the NumberProcessor class
         */
        if (predicate.test(item)) {
            submit(item);
        }
        this.subscription.request(1);
    }

    /*
     * If the subscription to NumberPublisher is closed, we also need to inform the
     * subscriber that there was a problem. Likewise, we need to inform the
     * subscriber when the subscription ended. In the onError() callback, add a call
     * to closeExceptionally(), and, in onComplete(), add a call to close()
     */
    @Override
    public void onError(Throwable throwable) {
        closeExceptionally(throwable);
    }

    @Override
    public void onComplete() {
        close();
    }
    /*
     * Now that your Processor is ready, inject it between NumberPublisher and
     * Subscriber:
     */
}
