package mod8;

import java.util.Collections;
import java.util.List;
import java.util.LongSummaryStatistics;
import java.util.Map;
import java.util.Optional;
import java.util.Set;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class usingCollectors {
    public static void main(String[] args) {
        // check1();
        // check2();
        // check3();
    }

    static void check1() {
        List<String> strArr = List.of("one", "two", "two", "three", "four", "five").stream()
                .collect(Collectors.toList());
        // System.out.println(strArr);
        Set<String> strSetArr = List.of("one", "two", "two", "three", "four", "five").stream()
                .collect(Collectors.toSet());
        // System.out.println(strSetArr);

        String joined1 = List.of("one", "two", "three", "four", "five").stream().collect(Collectors.joining());
        String joined2 = List.of("one", "two", "three", "four", "five").stream().collect(Collectors.joining(","));
        String joined3 = List.of("one", "two", "three", "four", "five").stream()
                .collect(Collectors.joining(",", "Prefix", "Suffix"));
        // System.out.println(joined1);
        // System.out.println(joined2);
        // System.out.println(joined3);

        Set<String> mapped1 = List.of("one", "two", "three", "four", "five").stream()
                .collect(Collectors.mapping((s) -> {
                    return s + "-suffix";
                }, Collectors.toSet()));
        // System.out.println(mapped1);

        List<String> mapped2 = List.of(Set.of("one", "two", "three"), Set.of("four", "five"), Set.of("six")).stream()
                .collect(Collectors.flatMapping((set) -> {
                    return set.stream();
                }, Collectors.toList()));
        // System.out.println(mapped2);

        Set<String> collected = List.of("Andreas", "David", "Eric").stream().collect(Collectors.filtering((name) -> {
            return name.length() < 6;
        }, Collectors.toSet()));
        // System.out.println(collected);

        /*
         * This special collector will allow you to finish the collection off with a
         * special function; for example, turning your collection into an immutable
         * collection:
         */
        Set<String> immutableSet = List.of("Andreas", "David", "Eric").stream()
                .collect(Collectors.collectingAndThen(Collectors.toSet(), (set) -> {
                    return Collections.unmodifiableSet(set);
                }));
        // System.out.println(immutableSet);
        // immutableSet.remove("David"); This will throw an error
        System.out.println(immutableSet);

    }

    static void check2() {
        long count = List.of("Andreas", "David", "Eric").stream().collect(Collectors.counting());
        System.out.println(count);

        Optional<Integer> smallest = Stream.of(1, 2, 3).collect(Collectors.minBy((a, b) -> {
            return a - b;
        }));
        System.out.println(smallest);

        Optional<Integer> biggest = Stream.of(1, 2, 3).collect(Collectors.maxBy((a, b) -> {
            return a - b;
        }));
        System.out.println(biggest);

        int sum1 = Stream.of(1d, 2d, 3d).collect(Collectors.summingInt((d) -> {
            return d.intValue();
        }));
        System.out.println(sum1);
        long sum2 = Stream.of(1d, 2d, 3d).collect(Collectors.summingLong((d) -> {
            return d.longValue();
        }));
        System.out.println(sum2);
        /* Similarly we have summingDouble */
        double average1 = Stream.of(1d, 2d, 3d).collect(Collectors.averagingInt((d) -> {
            return d.intValue();
        }));
        System.out.println(average1);
        /* Similarly we have averagingLong,averagingDouble */
    }

    static void check3() {
        /*
         * This collector will group elements according to a given function and collect
         * them according to a given collection type
         */
        Map<String, List<Car>> grouped1 = Stream.of(new Car("Toyota", 92), new Car("Kia", 104), new Car("Huyndai", 89),
                new Car("Toyota", 116), new Car("Mercedes", 209)).collect(Collectors.groupingBy(Car::getBrand));
        /*
         * Then, we apply the groupingBy() collector based on the brand of cars. This
         * will produce a Map<String, List<Car>> collection, where String is the brand
         * of the car, and the List contains all the cars for said brand. This will
         * always return Map; however, it is possible to define what kind of collection
         * to gather the grouped elements in.
         */
        // System.out.println(grouped1);

        Map<String, Set<Car>> grouped2 = Stream
                .of(new Car("Toyota", 92), new Car("Kia", 104), new Car("Kia", 104), new Car("Huyndai", 89),
                        new Car("Toyota", 116), new Car("Mercedes", 209))
                .collect(Collectors.groupingBy(Car::getBrand, Collectors.toSet()));
        // System.out.println(grouped2);

        /*
         * The groupingBy collector becomes even more powerful if you combine it with
         * another collector; for example, the reducing collector
         */
        Map<String, Optional<Car>> collected = Stream
                .of(new Car("Volvo", 195), new Car("Honda", 96), new Car("Volvo", 165), new Car("Volvo", 165),
                        new Car("Honda", 104), new Car("Honda", 201), new Car("Volvo", 215))
                .collect(Collectors.groupingBy(Car::getBrand, Collectors.reducing((carA, carB) -> {
                    if (carA.enginePower > carB.enginePower) {
                        return carA;
                    }
                    return carB;
                })));
        /*
         * First it grouped the using the brand like this { <V,[V195,V165,V165,V215]> ,
         * <H,[H104,H201]> }; then reduce them to { <V,[V215]>,<H,[H201]> }
         */
        // System.out.println(collected);

        /*
         * we group the cars by brand and then reduce them to only show the car of each
         * brand with the most powerful engine.
         */

        Map<String, List<Car>> grouped3 = Stream
                .of(new Car("Toyota"), new Car("Huyndai"), new Car("Kia"), new Car("Toyota"))
                .collect(Collectors.groupingByConcurrent(Car::getBrand));
        // System.out.println(grouped3);

        /*
         * The partitioningBy collector works in a similar way to the groupingBy
         * collector, with the difference being that it will group elements into two
         * collections that either matches a predicate or doesn't match a predicate. It
         * will wrap these two collections into Map, where the true keyword will
         * reference the collection of elements that matches the predicate, and the
         * false keyword will reference the elements that don't match the predicate
         */
        Map<Boolean, List<Car>> partitioned1 = Stream.of(new Car("Toyota", 92), new Car("Kia", 104),
                new Car("Hyundai", 89), new Car("Toyota", 116), new Car("Mercedes", 209))
                .collect(Collectors.partitioningBy((car) -> {
                    return car.enginePower > 100;
                }));
        // System.out.println(partitioned1);

        Map<Boolean, Set<Car>> partitioned2 = Stream.of(new Car("Toyota", 92), new Car("Kia", 104),
                new Car("Hyundai", 89), new Car("Toyota", 116), new Car("Mercedes", 209))
                .collect(Collectors.partitioningBy((car) -> {
                    return car.enginePower > 100;
                }, Collectors.toSet()));
        // System.out.println(partitioned2);

        /*
         * This allow you to create a map from your stream elements by defining a
         * mapping function, where you provide a key and value to put into the map.
         * Often, this is just a unique identifier in the element and the element itself
         * This can be a little bit tricky because if you provide a duplicate element,
         * then your pipeline will throw an IllegalStateException since Map is not
         * allowed duplicate keys:
         */
        Map<String, Integer> mapped1 = List.of("1", "2", "3", "4", "5").stream().collect(Collectors.toMap((s) -> {
            return s + "S";
        }, (s) -> {
            return Integer.valueOf(s);
        }));
        System.out.println(mapped1);

        /*
         * If you know you may have duplicate elements, then you can supply a merge
         * function to resolve that conflict:
         */
        Map<String, Integer> mapped2 = List.of("1", "2", "3", "4", "5", "1", "2").stream()
                .collect(Collectors.toMap((s) -> {
                    return s;
                }, (s) -> {
                    return Integer.valueOf(s);
                }, (a, b) -> {
                    return Integer.valueOf(b);
                }));
        // System.out.println(mapped2);

        LongSummaryStatistics statistics = Stream
                .of(new Car("Volvo", 165), new Car("Volvo", 165), new Car("Honda", 104), new Car("Honda", 201))
                .collect(Collectors.summarizingLong((e) -> {
                    return e.enginePower;
                }));
        System.out.println(statistics);

    }

    private static class Car {
        String brand;
        long enginePower = 89;

        /*
         * Java does not support default values in any functions . Here we can instead
         * overload our constructor to support optional arguments
         */
        Car(String brand) {
            this.brand = brand;
        }

        Car(String brand, long enginePower) {
            this.brand = brand;
            this.enginePower = enginePower;
        }

        public String getBrand() {
            return brand;
        }

        @Override
        public String toString() {
            return brand + " " + enginePower;
        }
    }
}
