package mod9.exercise3;

import java.util.function.Function;

import mod9.shared.Sensor;

/* Here we implement the Function<T, R> functional interface. Override the apply function */
public class ExtractBatteryHealth implements Function<Sensor, Integer> {
    @Override
    public Integer apply(Sensor sensor) {
        return sensor.batteryHealth();
    }
    /*
     * The main function in the interface is called apply, and it looks like this: R
     * apply(T); It defines a return value, R, and an input to the function. The
     * idea is that the return value and input don't have to be of the same type.
     */
}
