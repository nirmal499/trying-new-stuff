package mod9.exercise1;

import java.util.function.Predicate;

import mod9.shared.Sensor;

/* This HasWarning is the predicate class that
    check whether the battery status is below a threshold of 10, 
    which will symbolize 10% in our example 
*/
public class HasWarning implements Predicate<Sensor> {
    public static final int BATTERY_WARNING = 10;

    @Override
    public boolean test(Sensor sensor) {
        return sensor.batteryHealth() < BATTERY_WARNING;
    }
}