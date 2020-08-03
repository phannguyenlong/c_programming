import java.util.Scanner;

public class ScannerDemo {
    public static void main(String[] args) {
        try (Scanner input = new Scanner(System.in)) {
            System.out.print("Input N: ");
            String in = input.nextLine();
            System.out.println(in);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}