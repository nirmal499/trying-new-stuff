package mod9.exercise2;

import java.util.function.Consumer;
import mod9.shared.*;

public class ResetAlarm implements Consumer<Sensor> {
    /*
     * . The consumer has quite a simple API, the core function of which is called
     * accept() and doesn't return anything: void accept(T);
     */
    @Override
    public void accept(Sensor sensor) {
        sensor.triggered(false);
        sensor.batteryHealth(50);

        Ex2.alarmServiceNotified = false;
    }
}
