package mod1;

import java.util.*;

public class RandomAverage {
    public static void main(String[] args) {
        List<Double> numbers = new ArrayList<Double>();

        /* Generates a random number from 0 to 10000 */
        long numNode = Math.round(Math.random() * 10000);
        // System.out.println(numNode);

        for (int i = 0; i < numNode; i++) {
            /* Generate a random number between 0 to 100 */
            numbers.add(Math.random() * 100);
        }

        Iterator<Double> iterator = numbers.iterator();

        Double sum = 0.0;
        while (iterator.hasNext()) {
            sum += (Double) iterator.next();
        }

        /* Print out the average */
        System.out.println("Average: " + sum / numNode);
    }
}
