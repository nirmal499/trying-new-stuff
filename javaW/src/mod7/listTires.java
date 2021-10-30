package mod7;

import java.util.ArrayList;
import java.util.List;

class listTires {
    public static void main(String[] args) {
        List<Tire> tires = List.of(new Tire(17), new Tire(16), new Tire(18), new Tire(14), new Tire(15), new Tire(16));
        List<Tire> sorted = getSortedList(tires);
        System.out.println(sorted);
    }

    private static List<Tire> getSortedList(List<Tire> tires) {
        List<Tire> sorted = new ArrayList<>(tires);
        /*
         * The List.sort() method modifies the content of the list, so you need to copy
         * your immutable list of tires before sorting it
         */
        sorted.sort((t1, t2) -> t2.size - t1.size);
        /*
         * Returns an unmodifiable List containing the elements of the given Collection,
         * in its iteration order. If the given Collection is subsequently modified, the
         * returned List will not reflect such modifications
         */
        return List.copyOf(sorted);
    }

    public static final class Tire {
        private final int size;

        public Tire(int size) {
            this.size = size;
        }

        @Override
        public String toString() {
            return String.valueOf(size);
        }
    }
}