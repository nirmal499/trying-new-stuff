package mod9.exercise3;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.function.Function;

import mod9.shared.Fire;
import mod9.shared.Gateway;
import mod9.shared.Movement;
import mod9.shared.Sensor;

public class Ex3 {
    public static void main(String[] args) {
        List<Sensor> sensors = new ArrayList<>();
        sensors.add(new Gateway(34, false));
        sensors.add(new Gateway(14, true));
        sensors.add(new Fire(78, false, 21));
        sensors.add(new Gateway(74, false));
        sensors.add(new Gateway(8, false));
        sensors.add(new Movement(87, false, 45));
        sensors.add(new Gateway(18, false));
        sensors.add(new Fire(32, false, 23));
        sensors.add(new Gateway(9, false));
        sensors.add(new Movement(76, false, 41));

        // Function<Sensor, Integer> extractBatteryHealth = (a) -> {
        // return 0;
        // };

        ExtractBatteryHealth extractBatteryHealth = new ExtractBatteryHealth();

        Integer[] batteryHealths = sensors.stream().map(extractBatteryHealth).toArray(Integer[]::new);

        System.out.println(Arrays.toString(batteryHealths));
    }
}
