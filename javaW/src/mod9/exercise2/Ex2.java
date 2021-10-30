package mod9.exercise2;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Predicate;

import mod9.exercise1.HasAlarm;
import mod9.exercise1.HasWarning;
import mod9.shared.Gateway;
import mod9.shared.Sensor;

public class Ex2 {
    static boolean alarmServiceNotified = false;

    public static void main(String[] args) {
        List<Sensor> sensors = new ArrayList<>();
        sensors.add(new Gateway(34, false));
        sensors.add(new Gateway(14, true));
        sensors.add(new Gateway(74, false));
        sensors.add(new Gateway(8, false));
        sensors.add(new Gateway(18, false));
        sensors.add(new Gateway(9, false));

        Predicate<Sensor> hasAlarmOrWarning = new HasAlarm().or(new HasWarning());

        if (sensors.stream().anyMatch(hasAlarmOrWarning)) {
            System.out.println("Alarm or warning was triggered");
        }

        SendAlarm sendAlarm = new SendAlarm();

        ResetAlarm resetAlarm = new ResetAlarm();

        /*
         * chaining multiple consumers by using the andThen() function, which returns
         * the newly chained consumer: Consumer<T> andThen(Consumer<T>);
         */
        /*
         * Here inside filter we pass the Predicate , so the (sensor) ->
         * hasAlarmOrWarning.test(sensor)is basically what is done inside filter
         * automatically
         */
        /*
         * Basically filter allows only those sensors which are triggered means
         * isTriggered is true. And then in forEach we pass the Consumer which take
         * those allowed sensors, and apply sendAlarm and then apply resetAlarm in each
         * of the allowed sensors. Those Consumers take those allowed sensors as
         * arguments and do what they are supposed to do
         */
        sensors.stream().filter(hasAlarmOrWarning).forEach(sendAlarm.andThen(resetAlarm));

        if (alarmServiceNotified) {
            System.out.println("Alarm service notified");
        }

        /*
         * negate is same as Predicate<T> not(Predicate<T>) . Basically the 'not'
         * function returns the negated version of the predicate supplied, and it has
         * the exact same effect as calling negate() on the supplied predicate
         */
        if (sensors.stream().allMatch(hasAlarmOrWarning.negate())) {
            System.out.println("Nothing was triggered");
        }
    }
}
