package chap5;

/**
 * This is exercise 5.*
 * Error handling and writting and catch your own Exception
 */
public class SumParameter {
    public static void main(String[] args) {
        int sum = 0;
        try {
            if (args.length < 10) {
                throw new InvalidAmountParamException("Error: The number of parameter must be more than 10");
            } else {
                for (String index : args) {
                    try {
                        sum += Integer.parseInt(index);
                    } catch (NumberFormatException e) {
                        System.out.println("Error: The parameter must be an interger");
                        System.exit(1);
                    }
                }
            }
        } catch (InvalidAmountParamException e) {
            System.out.println(e.getMessage());
            for (String index : args)
                index = "0";
        }
        
        System.out.println("Sum of all parameter is: " + sum);
    }
}