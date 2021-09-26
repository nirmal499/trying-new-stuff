import java.util.*;

import java.io.Console;

class Datapoint {
    String key = "";
    Integer value = 0;

    Datapoint(String s, Integer v) {
        key = s;
        value = v;
    }
}

class SortByValue implements Comparator<Datapoint> {
    /* Used for sorting in ascending order */
    public int compare(Datapoint a, Datapoint b) {
        return a.value - b.value;
    }
}

public class AnalyzeInput {
    public static void main(String[] args) {
        List<String> text = new ArrayList<String>();
        Console cons;
        String line = "";
        /*
         * while ((cons = System.console()) != null && (line = cons.readLine()) != null)
         * { System.out.println("You have typed: " + line); }
         */
        while (!line.equals("*") && (cons = System.console()) != null && (line = cons.readLine()) != null) {
            // text.add(line);
            List<String> lineList = new ArrayList<String>(Arrays.asList(line.split(" ")));
            text.addAll(lineList);
        }
        System.out.println("You have typed: " + text);
        System.out.println("Word Count: " + text.size());

        Set<String> textSet = new HashSet<String>();
        textSet.addAll(text);
        /*
         * Since text contains a List of Strings that's why we used addAll instead of
         * add
         */

        System.out.println("\n" + textSet + "\n");

        Iterator<String> iterator = textSet.iterator();

        List<Datapoint> frequencies = new ArrayList<Datapoint>();

        while (iterator.hasNext()) {
            String s = (String) iterator.next();

            /* Get the amount of times this word shows up in the text */
            int freq = Collections.frequency(text, s);

            /* Print out the result */
            System.out.println(s + " appears " + freq + " times ");

            /* Create the object to be stored */
            Datapoint datapoint = new Datapoint(s, freq);

            /* Add Datapoints to the list */
            frequencies.add(datapoint);
            /*
             * Since there was only one object of Datapoint thats why we used add instead of
             * addAll
             */
        }

        /* Sorting in reverse order of the value */
        Collections.sort(frequencies, Collections.reverseOrder(new SortByValue()));

        System.out.println("\nResult is :\n");
        /*
         * Since our frequencies list is sorted in reverse order of the value. We can
         * display it here.
         */
        for (int i = 0; i < frequencies.size(); i++) {
            System.out.println(frequencies.get(i).value + " times for word " + frequencies.get(i).key);
        }

    }
}