import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

import comapre_interface.CompareByAge;
import student.student;

public class SampleCompare {
    public static void main(String[] args) {
        ArrayList<student> std_list = new ArrayList<>();
        
        // inital student
        std_list.add(new student("Phan Nguyen Long", "12CL", 20, 14472));
        std_list.add(new student("Tran Minh Nguyen", "12CA", 19, 14486));
        std_list.add(new student("Tran Huu Phuc", "12CC", 18, 14444));
        std_list.add(new student("Le Duc Duy", "11CL", 20, 24400));
        
        System.out.println("Before sorted:");
        for (student index : std_list) {
            index.sortDisplay();
        }

        // Sorted by name using Comperable
        Collections.sort(std_list);
        System.out.println("\nSorted by name: ");
        for (student index : std_list) {
            index.sortDisplay();
        }

        // Sorted by age using Comparator
        Collections.sort(std_list, new CompareByAge());
        System.out.println("\nSorted by age: ");
        for (student index : std_list) {
            index.sortDisplay();
        }

        // Sorted by ID using Comparator
        Collections.sort(std_list, new Comparator<student>() {
            // config Comparator right in class instead of creating new class like above
			@Override
			public int compare(student o1, student o2) {
				return o1.id > o2.id ? 1: -1;
			}            
        });
        System.out.println("\nSorted by ID: ");
        for (student index : std_list) {
            index.sortDisplay();
        }
    }
}