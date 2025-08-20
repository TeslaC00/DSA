import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;
import java.util.Set;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class ArrayListPractice {

    static List<Integer> numbersView = Arrays.asList(1, 20, 12, 1, 5, 15, 1, 12, 6, 76, 5, 69, 20);
    static List<Integer> numbersView2 = Arrays.asList(11, 2, 50, 65, 60, 7, 69, 20);

    public static void main(String[] args) {
        linkedListsAreEqual();
        isSubset();
    }

    /* Q. Write a program to sort an ArrayList of Strings alphabetically. */
    static void sortArrayList() {
        ArrayList<String> fruits = new ArrayList<>(
                Arrays.asList("Apple", "Cherry", "Mango", "Peach", "Banana"));

        System.out.println(fruits);
        // fruits.sort(null);
        Collections.sort(fruits);
        System.out.println(fruits);
    }

    /*
     * Q. Write a program to find the maximum element from an ArrayList of Integers.
     */
    static void maxElementInArrayList() {
        // System.out.println(Collections.max(numbersView));
        // numbersView.stream().max(Comparator.naturalOrder()).ifPresent(x ->
        // System.out.println(x));
        numbersView.stream().max(Integer::compareTo).ifPresent(x -> System.out.println(x));
    }

    /* Q. Write a program to remove all duplicate elements from an ArrayList. */
    static void removeDuplicatesInArrayList() {
        ArrayList<Integer> numbers = new ArrayList<>(numbersView);
        System.out.println(numbers);
        // Set<Integer> numberSet = new HashSet<>();
        // List<Integer> numbersUnique = numbers.stream().filter((num) -> {
        // boolean res = !numberSet.contains(num);
        // numberSet.add(num);
        // return res;
        // }).collect(Collectors.toList());
        List<Integer> numbersUnique = numbers.stream().distinct().toList();
        System.out.println(numbersUnique);
    }

    /*
     * Q. Create a LinkedList and perform various operations like add, remove, and
     * iterate over it.
     */
    static void linkedListOperations() {
        LinkedList<Integer> numbersLinked = new LinkedList<>(numbersView);
        System.out.println(numbersLinked);
        numbersLinked.add(16);
        System.out.println(numbersLinked);
        numbersLinked.addAll(Arrays.asList(1, 3, 7634, 123, 66, 23, 70));
        System.out.println(numbersLinked);
        numbersLinked.remove(Integer.valueOf(1));
        System.out.println(numbersLinked);
        numbersLinked.removeIf(num -> num == 1);
        numbersLinked.forEach(System.out::print);
        System.out.println();
    }

    /* Q. Write a program to find the intersection of two ArrayLists. */
    static void intersectionOfArrayLists() {
        HashSet<Object> numberSet = new HashSet<>(numbersView);
        List<Integer> intersection = numbersView2.stream().filter(numberSet::contains)
                .collect(Collectors.toList());
        System.out.println(numbersView);
        System.out.println(numbersView2);
        System.out.println(intersection);
    }

    /* Q. Write a program to shuffle the elements of an ArrayList. */
    static void shuffleArrayList() {
        ArrayList<Integer> numbers = new ArrayList<>(numbersView);
        System.out.println(numbersView);
        Collections.shuffle(numbers, new Random(69));
        System.out.println(numbers);
    }

    /*
     * Q. Write a program to find the second-largest element in an ArrayList of
     * Integers.
     */
    static void secondMaxElementInArrayList() {
        ArrayList<Integer> numbers = new ArrayList<>(numbersView);
        numbers.sort(null);
        System.out.println(numbers);
        // System.out.println(numbers.stream().sorted().toList().get(numbers.size() -
        // 2));
        // System.out.println(numbers.get(numbers.size() - 2));
        System.out.println(numbers.stream().distinct().sorted(Comparator.reverseOrder()).skip(1).findFirst());
    }

    /* Q. Write a program to find the frequency of each element in an ArrayList. */
    static void frequencyOfElementInArrayList() {
        ArrayList<Integer> numbers = new ArrayList<>(numbersView);
        // HashMap<Integer, Integer> frequency = new HashMap<>();
        // numbers.forEach(num -> {
        // if (frequency.containsKey(num))
        // frequency.put(num, frequency.get(num) + 1);
        // else
        // frequency.put(num, 1);
        // });
        System.out.println(numbers);
        // System.out.println(numbers.stream().collect(Collectors.toMap(num -> num, num
        // -> 1, Integer::sum)));
        System.out.println(numbers.stream().collect(Collectors.groupingBy(num -> num, Collectors.counting())));
        // System.out.println(frequency);
    }

    /* Q. Write a program to find the kth smallest element in an ArrayList. */
    static void smallestKElementInArrayList() {
        int k = 3;
        System.out.println(numbersView);
        System.out.println(numbersView.stream().distinct().sorted().skip(k - 1).findFirst());
    }

    /* Q. Write a program to merge two ArrayLists into a single ArrayList. */
    static void mergeArrayLists() {
        ArrayList<Integer> merged = new ArrayList<>(numbersView);
        merged.addAll(numbersView2);

        // List<Integer> merged = Stream.concat(numbersView.stream(),
        // numbersView2.stream()).distinct().toList();

        System.out.println(numbersView);
        System.out.println(numbersView2);
        System.out.println(merged);
    }

    /* Q. Write a program to find the intersection of multiple Sets. */
    @SafeVarargs // I Know what i am doing and I promise i wont pass Set of different types
                 // (compiles to Set[] with no type)
    static void intersectionOfSets(Set<Integer>... sets) {
        // HashSet<Integer> intersection = new HashSet<>(sets[0]);
        // for (int i = 1; i < sets.length; i++) {
        // intersection.retainAll(sets[i]);
        // }
        // System.out.println(intersection);

        // ArrayList<Set<Integer>> allSets = new ArrayList<>();
        // for (Set<Integer> set : sets) {
        // allSets.add(set);
        // }
        // allSets.stream().reduce((left, right) ->
        // left.stream().filter(right::contains).collect(Collectors.toSet()));

        Set<Integer> intersections = Arrays.stream(sets).reduce((left, right) -> {
            Set<Integer> temp = new HashSet<>(left);
            temp.retainAll(right);
            return temp;
        }).orElse(Set.of());
        System.out.println(intersections);
    }

    /* Q. Write a program to check if two LinkedLists are equal. */
    static void linkedListsAreEqual() {
        LinkedList<String> fruits = new LinkedList<>(List.of("banana", "apple", "mango", "orange"));
        LinkedList<String> fruits2 = new LinkedList<>(List.of("apple", "mango", "orange", "banana"));
        // System.out.println(fruits.equals(fruits2)); // order matters
        System.out.println(new HashSet<>(fruits).equals(new HashSet<>(fruits2))); // order-agnostic
    }

    /* Q. Write a program to check if a HashSet is a subset of another HashSet. */
    static void isSubset() {
        HashSet<Integer> numberSet = new HashSet<>(numbersView);
        HashSet<Integer> subset = new HashSet<>(Arrays.asList(1, 20, 5, 15, 69));
        // System.out.println(subset.stream().allMatch(numberSet::contains));
        System.out.println(numberSet.containsAll(subset));
    }

}