package mod9.exercise1;

import java.util.function.Predicate;

import mod9.shared.Sensor;

/*  This HasAlarm is the predicate class, the predicate that describes
    whether a sensor has a triggered alarm
 */
public class HasAlarm implements Predicate<Sensor> {
    /*
     * The predicate API looks like this: boolean test(T t);
     */
    @Override
    public boolean test(Sensor sensor) {
        return sensor.triggered();
    }
    /*
     * This test function, return the trigger status of the sensor
     */
}
