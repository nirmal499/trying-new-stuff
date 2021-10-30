package mod9.exercise2;

import java.util.function.Consumer;

import mod9.shared.Sensor;

public class SendAlarm implements Consumer<Sensor> {
    /*
     * . The consumer has quite a simple API, the core function of which is called
     * accept() and doesn't return anything: void accept(T);
     */
    @Override
    public void accept(Sensor sensor) {
        if (sensor.triggered()) {
            Ex2.alarmServiceNotified = true;
        }
    }
}
