package exception;

public class ThrowVSThrows {
    public static int devide(int a, int b) {
        if (b == 0) {
            // thrown allow throw only 1 specific Exception
            throw new ArithmeticException("Error: b must different from 0");
        }
        return a / b;
    }
    
    // throws is that we can thrown more than one exception
    public static void throwsExample() throws NullPointerException, ArithmeticException {
        String str = null;
        int a = str.length();
        System.out.println(a);
    }

    public static void main(String[] args) {
        System.out.println("=======Example Throws=====");
        try {
            throwsExample();
        } catch (Exception e) {
            System.out.println("Exception throm out by Throws");
        }

        System.out.println("\n=======Example Throw=====");
        try {
            devide(10, 0);
        } catch (ArithmeticException e) {
            System.out.println("Exception: " + e.getMessage());
            e.printStackTrace(); // output the stack trace
            System.out.println("Exception throw out by Thorw");
        }
    }
}