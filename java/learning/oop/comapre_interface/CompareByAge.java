package comapre_interface;

import java.util.Comparator;
import student.student;

public class CompareByAge implements Comparator<student> {

    @Override
    public int compare(student o1, student o2) {
        // compare by age
        return o1.age > o2.age ? 1 : -1;
        // if return 1 ==> swap 2 object, if -1 do nothing
    }
    
}