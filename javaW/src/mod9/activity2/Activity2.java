package mod9.activity2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.function.Function;
import java.util.stream.Stream;

import mod9.exercise3.ExtractBatteryHealth;
import mod9.shared.*;

public class Activity2 {
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

        /*
         * Instead of instantiating the ExtractBatteryHealth functional interface, use a
         * lambda andstore a reference to that
         */
        Function<Sensor, Integer> extractBatteryHealth = sensor -> sensor.batteryHealth();

        // ExtractBatteryHealth extractBatteryHealth = new ExtractBatteryHealth();

        Integer[] batteryHealths = sensors.stream().map(extractBatteryHealth).toArray(Integer[]::new);

        System.out.println(Arrays.toString(batteryHealths));

        System.out.println(loopedAverageHealth(batteryHealths));

        System.out.println(streamedAverageHealth(batteryHealths));

    }

    private static double loopedAverageHealth(Integer[] batteryHealths) {
        double average = 0;
        for (int i = 0; i < batteryHealths.length; i++) {
            average += batteryHealths[i];
        }
        average = average / batteryHealths.length;
        return average;
    }

    private static double streamedAverageHealth(Integer[] batteryHealths) {
        return Stream.of(batteryHealths).mapToDouble(Integer::intValue).average().orElse(0);
    }
}
