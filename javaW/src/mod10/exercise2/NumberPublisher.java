package mod10.exercise2;

import java.util.concurrent.SubmissionPublisher;
import java.util.Timer;
import java.util.TimerTask;
import java.util.function.Supplier;

/*  We will continue using the basic SubmissionPublisher supplied in the Flow
    library, but in this exercise, we'll create our own subclass. Create a new class
    called NumberPublisher. This should extend SubmissionPublisher 
*/
public class NumberPublisher extends SubmissionPublisher<String> {
    /*
     * A Supplier is a functional interface that is often used to deliver results –
     * to anyone and anything.
     */
    final Supplier<String> supplier;

    final Timer timer = new Timer();
    /*
     * There are two different ways to let the publisher send items to the connected
     * subscribers – using either submit() or offer(). submit() works in a
     * fire-andforget fashion, while offer() lets the publisher retry sending the
     * item once using a handler. In our case, submit() would work just fine. But,
     * before you can submit, you need some data. Add a Supplier to the Publisher
     * using dependency injection:
     */
    final TimerTask timerTask = new TimerTask() {
        @Override
        public void run() {
            try {
                /*
                 * Inside the run() method of TimerTask, add a call to submit() and get the data
                 * from the Supplier
                 */
                submit(supplier.get());
            } catch (Exception e) {
                closeExceptionally(e);
            }
        }
    };

    public NumberPublisher(Supplier<String> supplier) {
        this.supplier = supplier;
        this.timer.schedule(timerTask, 1000, 1000);
    }

    /*
     * When the publisher is shutting down, so should Timer. Override the
     * publisher's close() method, and add a call to the cancel() method of Timer
     * just before the publisher is about to shut down
     */
    @Override
    public void close() {
        timer.cancel();
        super.close();
    }
}
