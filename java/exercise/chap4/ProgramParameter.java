package chap4;

/**
 * This is exercise 4.1
 * This program will read parameter from command line
 * ex: java program_name 1 2 3 4  - (1 2 3 4 is parameter in this scenario)
 */
public class ProgramParameter {
    public static void main(String[] args) {
        int sum = 0;
        for (String index : args) {
            sum += Integer.parseInt(index);
        }
        System.out.println(sum);

        // this part for ex 4.2
        String test = "That ’s it! You people have stood in my way long enough . I’m going to clown college !";
        System.out.println(test == "That ’s it! You people have stood in my way long enough . I’m going to clown college !");
    }
}