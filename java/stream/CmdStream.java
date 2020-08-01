import java.io.*;
// import java.util.Arrays;

// This will read from the input from the console
/** There are 2 apprpoach
 * 1. use InputStreamReader
 * 2. use java.io.Console
 */
public class CmdStream {
    public void perStream() throws IOException {
        BufferedReader in = null;
        try {
            in = new BufferedReader(new InputStreamReader(System.in));
            while (true) {
                System.out.print("$> ");
                String input = in.readLine();
                if (input.equalsIgnoreCase("exit"))
                    break;
                else if (input.equalsIgnoreCase("hi"))
                    System.out.println("hello");
                else if (input.equalsIgnoreCase("test"))
                    System.out.println("Pass");
                else
                    System.out.println("Invalid command");
            }
        } finally {
            if (in != null)
                in.close();
        }
    }

    public void perConsole() throws IOException {
        Console c = System.console();
        try {
            while (true) {
                System.out.print("$> ");
                String input = c.readLine();
                switch (input) {
                    case "exit":
                        return;
                    case "login": {
                        char[] passwd = c.readPassword("Password: ");
                        // if (Arrays.equals(passwd, "test".toCharArray()))
                        if (String.valueOf(passwd).equals("test")) // use String.valueof() instead str.toString()
                            System.out.println("Welcome");
                        else
                            System.out.println("Wrong password. Permission denied");
                    }
                        break;
                    default:
                        System.out.println("Unknow command: " + input);
                }
            }
        } finally {}
    }
    
    public static void main(String[] args) throws IOException {
        CmdStream reader = new CmdStream();
        // System.out.println("=====Per Stream Running=====");
        // reader.perStream();
        System.out.println("=====Per Console Running=====");
        reader.perConsole();
    }
}