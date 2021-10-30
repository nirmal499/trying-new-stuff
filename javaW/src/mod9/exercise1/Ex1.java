package mod9.exercise1;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Predicate;

import mod9.shared.Gateway;
import mod9.shared.Sensor;

public class Ex1 {
    public static void main(String[] args) {
        List<Sensor> sensors = new ArrayList<>();
        sensors.add(new Gateway(34, false));
        sensors.add(new Gateway(14, true));
        sensors.add(new Gateway(74, false));
        sensors.add(new Gateway(8, false));
        sensors.add(new Gateway(18, false));
        sensors.add(new Gateway(9, false));

        // Predicate<T> and(Predicate<T>)
        // Predicate<T> or(Predicate<T>)
        // Predicate<T> not(Predicate<T>)
        /*
         * The and function will combine two or more predicates, ensuring that every
         * predicate supplied returns true. The or function is equivalent to a logical
         * OR, letting you short-circuit the predicate chain when require, ensuring that
         * atleast one of predicate supplied returns true
         */
        Predicate<Sensor> hasAlarmOrWarning = new HasAlarm().or(new HasWarning());

        for (Sensor sensor : sensors) {
            if (new HasAlarm().test(sensor)) {
                System.out.println("Alarm was triggered");
            }

            if (hasAlarmOrWarning.test(sensor)) {
                /*
                 * Here the hasAlarmOrWarning.test(sensor) checking : new HasAlarm.test(sensor)
                 * || new HasWarning().test(sensor)
                 */
                System.out.println("Alarm or warning was triggered");
            }
        }

    }
}
