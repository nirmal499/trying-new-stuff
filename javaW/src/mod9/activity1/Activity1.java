package mod9.activity1;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.function.Predicate;

import mod9.exercise1.HasAlarm;
import mod9.exercise1.HasWarning;
import mod9.shared.Gateway;
import mod9.shared.Sensor;

public class Activity1 {
    /*
     * Rewriting the program Ex1.java once more, adding a scanner to your program to
     * toggle sensor states from the command line. Each sensor should be capable of
     * at least toggling the battery health and triggered status. When a sensor has
     * updated, you should check the system for changes and generate a proper
     * response on the command line if a warning or alarm has been triggered.
     */
    public static void main(String[] args) {
        List<Sensor> sensors = new ArrayList<>();
        sensors.add(new Gateway(34, false));
        sensors.add(new Gateway(44, false));
        sensors.add(new Gateway(74, false));
        sensors.add(new Gateway(56, false));
        sensors.add(new Gateway(18, false));
        sensors.add(new Gateway(92, false));

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter sensor index:");

        while (scanner.hasNext()) {
            int index = scanner.nextInt();
            if (index < 0 || index >= sensors.size()) {
                continue;
            }

            System.out.print("Enter (b)attery health or toggle (t)riggered status:");
            String action = scanner.next();

            if (action.toLowerCase().equals("b")) {
                System.out.print("Enter battery health:");
                sensors.get(index).batteryHealth(scanner.nextInt());

            } else if (action.toLowerCase().equals("t")) {
                sensors.get(index).triggered(!sensors.get(index).triggered());
            } else {
                System.out.println("Error either enter b or t");
            }

            printAlarmStatus(sensors);

            System.out.print("Enter sensor index:");
        }
        scanner.close();
    }

    private static void printAlarmStatus(List<Sensor> sensors) {
        Predicate<Sensor> hasAlarmOrWarning = new HasAlarm().or(new HasWarning());

        boolean alarmOrWarning = false;

        for (Sensor sensor : sensors) {
            if (hasAlarmOrWarning.test(sensor)) {
                alarmOrWarning = true;
            }
        }

        if (alarmOrWarning) {
            System.out.println("Alarm, or warning, was triggered!");

            for (Sensor sensor : sensors) {
                System.out.println(sensor.batteryHealth() + ", " + sensor.triggered());
            }
        }
    }
}
