package exception.user_defined;

/**
 * This is the example of using Checked Exception
 */
public class MotorAge {
    private int age;

    MotorAge(int age) throws MotorAgeException{ // throw Exception to main
        setAge(age);
    }
    
    public void setAge(int age) throws MotorAgeException { // throw an Exception to contructor
        if (age < 16) {
            throw new MotorAgeException("Invalid Age: Must be higher than 16");
        } else {
            this.age = age;
        }
    }

    public int getAge() {
        return age;
    }

    public static void main(String[] args) {
        System.out.println("=====Seft defined Checked Exception demo=====\n");
        try { // cause there is an Exception ==> Must you try catch
            MotorAge age = new MotorAge(15);
            System.out.println("[+] Try block:");
            System.out.println("Person age is " + age.getAge());
        } catch (MotorAgeException e) {
            System.out.println("[+] Catch block: Error occur");
            System.out.println(e.getMessage());
            e.printStackTrace(); // Output the stack trace (setAge -> contructor -> main)
        }
    }
}