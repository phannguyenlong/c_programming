import java.util.ArrayList;
import java.util.List;

import student.student;
import student.Person;

/**
 * This class use for demonstrate example about generic
 */
public class GenericClassTest {
    /**
     * This is generic function
     * Must extends Comparable in oder to use compareTo
     * Must extends Person to config that generic class only accept T that belongs to class Person (optional)
     */
    public static <T extends Person & Comparable<T>> T findFirstName(T[] arr) { // Pass List to funcion using toArray
        T first = arr[0];
        for (int i = 0; i < arr.length; i++) {
            if (arr[i].compareTo(first) < 0) {
                first = arr[i];
            }
        }
        return first;
    }
    
    public static <T extends Person & Comparable<T>> T findFirstName(List<T> arr) { // Pass list to function without using toArray
        T first = arr.get(0);
        for (T index : arr) {
            if (index.compareTo(first) < 0) {
                first = index;
            }
        }
        return first;
    }
    public static void main(String[] args) {
        List<student> std_list = new ArrayList<student>();
        std_list.add(new student("Phan Nguyen Long", "CS", 12, 14472));
        std_list.add(new student("Le Duc Duy", "ME", 20, 14486));
        std_list.add(new student("Tran Minh Nguyen", "EEIT", 20, 14485));
        
        for (student index : std_list) {
            index.sortDisplay();
        }

        System.out.println("\nFirst name student is: ");
        // Passing List to function using to Array
        findFirstName(std_list.toArray(new student[std_list.size()])).sortDisplay();

        // Passing List to function without using to Array
        findFirstName(std_list).sortDisplay();
    }
}