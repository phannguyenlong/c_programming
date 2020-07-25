package exception.user_defined;

/**
 * This is the example of usign Unchecked Exception
 */
public class AutoAge {
    private int age;

    AutoAge(int age) throws AutoAgeException {
        setAge(age);
    }

    public void setAge(int age) throws AutoAgeException {
        if (age < 18) {
            throw new AutoAgeException("Invalid Age: Must be higher than 18");
        } else {
            this.age = age;
        }
    }

    public int getAge() {
        return age;
    }
    public static void main(String[] args) {
        System.out.println("=====Seft defined Checked Exception demo=====\n");
        try {
            AutoAge age = new AutoAge(16);
            System.out.println("[+] Try block:");
            System.out.println("Person age is " + age.getAge());
        } catch (AutoAgeException e) {
            System.out.println("[+] Catch block: Error occur");
            System.out.println(e.getMessage());
            e.printStackTrace(); // Output the stack trace (setAge -> contructor -> main)
        }
    }
}