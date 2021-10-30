package mod8;

import java.util.*;
import java.util.stream.*;

public class streams {

    /*
     * In Java, there are four types of streams: Stream, which is used for streaming
     * objects; IntStream, which is for streaming integers; LongStream, which
     * streams longs; and finally, DoubleStream, which, of course, streams doubles.
     * All of these streams work in exactly the same way, except they're specialized
     * to work with their respective types
     */
    public static void main(String[] args) {
        /* 16 different terminal operations in the Stream API */

        // check1();
        // check2();
        // check3();
        // check4();
        // check5();
        // check6();

        /* Intermediate Operations */
        // check7();
        // check8();

    }

    static void check1() {
        Stream.of(1, 4, 6, 2, 3, 7).forEach((n) -> {
            System.out.println(n);
        });
        System.out.println("==============================================");
        /*
         * If this operation is applied on a parallel pipeline, the order in which
         * elements are acted on will not be guaranteed
         */
        Stream.of(1, 4, 6, 2, 3, 7).parallel().forEach((n) -> {
            System.out.println(n);
        });
        System.out.println("==============================================");

        Stream.of(1, 4, 6, 2, 3, 7).parallel().forEachOrdered((n) -> {
            System.out.println(n);
        });
    }

    static void check2() {
        Object[] array1 = Stream.of(1, 4, 6, 2, 3, 7).toArray();
        Integer[] array2 = Stream.of(1, 4, 6, 2, 3, 7).toArray(Integer[]::new);
        Integer[] array3 = Stream.of(1, 4, 6, 2, 3, 7).toArray(elements -> new Integer[elements]);
        System.out.println(array1[array1.length - 1]);
        System.out.println(array2[array2.length - 1]);
        System.out.println(array3[array3.length - 1]);
    }

    static void check3() {
        /*
         * Identity – an element that is the initial value of the reduction operation
         * 
         * Accumulator – a function that takes two parameters: a partial result of the
         * reduction operation and the next element of the stream
         * 
         * Combiner – a function used to combine the partial result of the reduction
         * operation when the reduction is PARALLELIZED or when there's a mismatch
         * between the types of the accumulator arguments
         */
        int sum1 = Stream.of(1, 7, 4, 3, 9, 6).reduce(0, (total, i) -> {
            // System.out.println(total + i);
            return total + i;
        });
        /*
         * 
         * The accumulator adds up the result of the combining function to the identity
         * value, which, in this case, is the total sum of the reduction
         * 
         */
        int sum2 = Stream.of(1, 2, 4, 6).parallel().reduce(0, (total, i) -> {
            // System.out.println(total + i);
            return total + i;
        }, (a, b) -> {
            System.out.println(a + b);
            /*
             * 4+6 becomes 10; 1+2 becomes 3; then 10+3 becomes 13
             */
            return a + b;

        });

        System.out.println(sum1);
        System.out.println(sum2);
    }

    static void check4() {
        List<Integer> items1 = Stream.of(6, 3, 8, 12, 3, 9).collect(Collectors.toList());
        System.out.println(items1);

        List<Integer> items2 = Stream.of(6, 3, 8, 12, 3, 9).collect(() -> {
            return new ArrayList<Integer>();
        }, (list, i) -> {
            list.add(i);
        }, (list, elements) -> {
            list.addAll(elements);
        });
        System.out.println(items2);

        List<Integer> items3 = Stream.of(6, 3, 8, 12, 3, 9).collect(ArrayList::new, List::add, List::addAll);
        System.out.println(items3);

    }

    static void check5() {
        Optional<Integer> min = Stream.of(6, 3, 8, 12, 3, 9).min((a, b) -> {
            return a - b;
        });
        // System.out.println(min);

        Optional<Integer> max = Stream.of(6, 3, 8, 12, 3, 9).max((a, b) -> {
            return a - b;
        });
        // System.out.println(max);

        OptionalDouble avg = IntStream.of(6, 3, 8, 12, 3, 9).average();
        // System.out.println(avg);

        long count = Stream.of(6, 3, 8, 12, 3, 9).count();
        // System.out.println(count);

        /*
         * The anyMatch() terminal operator will return true if any of the elements in
         * the stream
         */
        boolean matched1 = Stream.of(6, 3, 8, 12, 3, 9).anyMatch((e) -> {
            return e > 10;
        });
        /*
         * As there is an element with a value above 10, this pipeline will return true
         */
        // System.out.println(matched1);

        /*
         * The allMatch() terminal operator will return true if all the elements in the
         * stream match the specified predicate
         */
        boolean matched2 = Stream.of(6, 3, 8, 12, 3, 9).allMatch((e) -> {
            return e > 10;
        });
        /*
         * Since this source has elements whose values are below 10, it should return
         * false
         */
        // System.out.println(matched2);

        boolean matched3 = Stream.of(6, 3, 8, 12, 3, 9).noneMatch((e) -> {
            return e > 10;
        });
        /*
         * Because the stream has elements of values above 10, this will also return
         * false
         */
        // System.out.println(matched3);

        Optional<Integer> firstElement1 = Stream.of(6, 3, 8, 12, 3, 9).findFirst();
        // System.out.println(firstElement1);

        /*
         * It's ideal when you just need to know whether there are any elements left but
         * don't really care about which remain:
         */
        Optional<Integer> firstElement2 = Stream.of(7, 9, 3, 4, 1).findAny();
        // System.out.println(firstElement2);

        Iterator<Integer> iterator = Stream.of(1, 2, 3, 4, 5, 6).iterator();
        while (iterator.hasNext()) {
            Integer next = iterator.next();
            System.out.println(next);
        }

    }

    static void check6() {
        /*
         * sum() :- This terminal operation is only available for IntStream, LongStream,
         * and DoubleStream.
         */
        int intSum = IntStream.of(1, 7, 4, 3, 9, 6).sum();
        // System.out.println(intSum);

        long longSum = LongStream.of(7L, 4L, 9L, 2L).sum();
        // System.out.println(longSum);

        double doubleSum = DoubleStream.of(5.4, 1.9, 7.2, 6.1).sum();
        // System.out.println(doubleSum);

        IntSummaryStatistics intStats = IntStream.of(7, 9, 3, 4, 1).summaryStatistics();
        System.out.println(intStats);

        LongSummaryStatistics longStats = LongStream.of(6L, 4L, 1L, 3L, 7L).summaryStatistics();
        System.out.println(longStats);

        DoubleSummaryStatistics doubleStats = DoubleStream.of(4.3, 5.1, 9.4, 1.3, 3.9).summaryStatistics();
        System.out.println(doubleStats);
    }

    static void check7() {
        Stream.of(1, 2, 3, 4, 5, 6).filter((i) -> {
            return i > 3;
        }).forEach(System.out::println);

        System.out.println("\n========================================================\n");
        Stream.of("5", "3", "8", "2").map((s) -> {
            return Integer.parseInt(s);
        }).forEach((i) -> {
            System.out.println(i > 3);
        });
        System.out.println("\n========================================================\n");

        /*
         * flatMap:- This gives you an easy way of flattening a multidimensional data
         * structure into one single stream; for example, a stream of objects that
         * themselves contain objects or arrays
         */
        Stream.of(List.of(1, 2, 3), List.of(4, 5, 6), List.of(7, 8, 9)).flatMap((l) -> {
            return l.stream();
        }).forEach((i) -> {
            System.out.print(i);
        });
        System.out.println("\n========================================================\n");

        Stream.of(1, 2, 2, 2, 2, 3).distinct().forEach((i) -> {
            System.out.print(i);
        });

        System.out.println("\n========================================================\n");
        Stream.of(1, 3, 6, 4, 5, 2).sorted().forEach((i) -> {
            System.out.print(i);
        });
        System.out.println();
        /*
         * The second version of the sorted operation takes a Comparator as an argument,
         * and will return the sorted elements accordingly
         */
        Stream.of(1, 3, 6, 4, 5, 2).sorted((a, b) -> a - b).forEach((i) -> {
            System.out.print(i);
        });

        System.out.println("\n========================================================\n");

        Stream.of(1, 2, 3, 4, 5, 6).unordered().forEach((i) -> {
            System.out.print(i);
        });
        System.out.println();
        Stream.of(1, 2, 3, 4, 5, 6).parallel().unordered().forEach((i) -> {
            System.out.print(i);
        });
        System.out.println("\n========================================================\n");
        /*
         * This returns a new stream with n number of elements. If the number of
         * elements is fewer than the requested limit, it has no effect
         */
        Stream.of(1, 2, 3, 4, 5, 6).limit(3).forEach((i) -> {
            System.out.print(i);
        });
        System.out.println("\n========================================================\n");

    }

    static void check8() {
        /*
         * skip:- This skips the first n elements of this stream and returns the
         * remaining elements in a new stream
         */
        Stream.of(1, 2, 3, 4, 5, 6).skip(3).forEach((i) -> {
            System.out.print(i);
        });
        System.out.println("\n==============================================================\n");

        /*
         * Boxed:- The special primitive streams, IntStream, LongStream, and
         * DoubleStream, all have access to the boxed() operation. This operation will
         * "box" each primitive element in the class version of said type, and return
         * that stream
         */
        /*
         * This example will take each primitive stream, box it in the corresponding
         * object type, and then print the value together with the class name of the
         * type
         */
        IntStream.of(1, 2).boxed().forEach((i) -> {
            System.out.println(i + i.getClass().getSimpleName());
        });
        System.out.println();
        LongStream.of(3, 3).boxed().forEach((l) -> {
            System.out.println(l + l.getClass().getSimpleName());
        });
        System.out.println();
        DoubleStream.of(5, 6).boxed().forEach((d) -> {
            System.out.println(d + d.getClass().getSimpleName());
        });

        System.out.println("\n==============================================================\n");

        /*
         * Peek:- This intermediate operation is mainly used to examine the stream after
         * other intermediate operations have been applied.
         */
        long count = Stream.of(6, 5, 3, 8, 1, 9, 2, 4, 7, 0).peek((i) -> {
            System.out.print(i);
        }).filter((i) -> {
            return i < 5;
        }).peek((i) -> {
            System.out.print(i);
        }).map((i) -> {
            return String.valueOf(i);
        }).peek((p) -> {
            System.out.print(p);
        }).count();
        System.out.println("\n" + count);

        // For 6 : peek [It prints 6] ; then 6 was not able to pass through filter
        // For 5 : It is same as 6
        // For 3 : peek [It prints 3] ; after filter ; peek [It prints 3] ; map [makes 3
        // to "3"]; peek [It prints "3"] ; count gives 1

        System.out.println("\n==============================================================\n");

        /*
         * Use of peek : While the peek() operation is most commonly used to examine
         * elements as they traverse the pipeline, it is also possible to mutate the
         * elements of the stream using these operations
         */
        long sum = Stream.of(new MyItem(1), new MyItem(2), new MyItem(3)).peek((item) -> {
            item.value = 0;
        }).mapToInt((item) -> {
            return item.value;
        }).sum();
        System.out.println(sum);

    }

    static class MyItem {
        int value;

        public MyItem(int value) {
            this.value = value;
        }
    }

}
