package exception;

public class TryCatchFinally {
    public static void main(String[] args) {
        System.out.println("=====Try Catch Finally demos=====\n");
        try {
            // int a = 10 / 0; // this will create an Exception caues can't divide by 0
            String str = null; // create a null string
            System.out.println("[+] Run is try block");
            // System.out.println("Program output: " + a);
            System.out.println(str.length()); // this will cause error NullPointerException

        } catch (ArithmeticException e) { // Catch the Exception name ArithmeticException
            System.out.println("Exception occur: ArithmeticException");
            System.out.println("[+] Run is catch block");
            System.out.println("Error: " + e);

        } catch (NullPointerException e) { // Multiple catch wih try
            System.out.println("Exception occur: NullPointerException");
            System.out.println("[+] Run is catch block");
            System.out.println("Error: " + e);

        } catch (Exception e) { // Catch all Exception
            System.out.println("Exception occur: Every Exception");
            System.out.println("[+] Run is catch block");
            System.out.println("Error: " + e);

        } finally { // Finally always run no matter what
            System.out.println("Run in Finally Block"); 
            System.out.println("[+] Finally always run");
        }

        System.out.println("\n[+] Program end...");
    }
}