package mod10.exercise1;

import java.util.concurrent.Flow;

/*  Flow doesn't come with any already available implementations of Subscriber,
    so we will need to implement our own Subscriber. Create a new class called
    LipsumSubscriber, and allow it to implement the Flow.Subscriber interface. 
*/
public class LipsumSubscriber implements Flow.Subscriber<String> {

    /*
     * The subscriber has four methods to implement. The onSubscribe method will be
     * called by the publisher when the Subscription object has been created.
     * Usually, you'll store a reference to that subscription so that you can issue
     * requests to the publisher, create a Flow.Subscription member variable in your
     * LipsumSubscriber class, and store the reference from the onSubscribe method
     */
    private Flow.Subscription subscription;

    /*
     * Usually, you'll also request at least one item when the subscription has been
     * created. Use the request method to ask for one item from the publisher
     */
    @Override
    public void onSubscribe(Flow.Subscription subscription) {
        this.subscription = subscription;
        this.subscription.request(1);
    }

    /*
     * To keep getting more items from the publisher, we need to keep requesting
     * them – this is what is called backpressure. It's the subscriber who is in
     * control in terms of how many items it can handle at a time. In this exercise,
     * we'll handle one item at a time and then request another. Request another
     * item after you've printed the current item to the console
     */
    @Override
    public void onNext(String item) {
        // System.out.println("Word is : " + item); This will not print anything
        System.out.println(item);
        this.subscription.request(1);
    }

    /*
     * The subscriber can use the methods onError and onComplete to perform a
     * cleanup and make sure that no resources are kept in vain.
     */
    @Override
    public void onError(Throwable throwable) {
        System.out.println("error: " + throwable.getMessage());

        throwable.printStackTrace();
    }

    @Override
    public void onComplete() {
        System.out.println("completed");
    }
}
