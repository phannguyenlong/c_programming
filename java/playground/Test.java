import java.util.ArrayList;
import java.util.Arrays;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Test {
    public static void main(String[] args) {
        double res = 0;
        Pattern pattern;
        Matcher matcher;
        String[] opLookup = {"+", "-", "/", "*"};
        // String op = "2+12/3*5+4/2+2";
        String op = "92 - 6 * 4/3+5";

        pattern = Pattern.compile("-?\\d+");
        matcher = pattern.matcher(op);
        ArrayList<String> operands = new ArrayList<>();
        while (matcher.find()) {
            operands.add(op.substring(matcher.start(), matcher.end()));
        }

        // List<String> operands = asList(op.split("[\\+\\-\\*\\/]"));
        ArrayList<String> operations = new ArrayList<>();

        pattern = Pattern.compile("[+-/*]");
        matcher = pattern.matcher(op);

        while (matcher.find()) {
            operations.add(new String(op.substring(matcher.start(), matcher.end())));
        }

        for (String index : operands) {
            System.out.println(index);
        }
        for (String index : operations) {
            System.out.println(index);
        }

        // calculate
        // Calculate * and / first
        for (String index : operations) {
            if (index.equals("*") || index.equals("/")) {
                int i = operations.indexOf(index);
                double tmp = index.equals("*")
                        ? Double.parseDouble(operands.get(i)) * Double.parseDouble(operands.get(i + 1))
                        : Double.parseDouble(operands.get(i)) / Double.parseDouble(operands.get(i + 1));
                operands.set(i + 1, String.valueOf(tmp));
                operations.set(i, String.valueOf(tmp));
            }
        }
        // Calculate + and -
        int i = 0;
        String prevIndex = "";
        for (String index : operations) {
            if (Arrays.asList(opLookup).contains(operations.get(i))) {
                if (prevIndex.equals("+"))
                    res += Double.parseDouble(operands.get(i));
                else if (prevIndex.equals("-"))
                    res -= Double.parseDouble(operands.get(i));
                else
                    res = Double.parseDouble(operands.get(i));
                prevIndex = index;
            }
            i++;
        }
        if (prevIndex.equals("+"))
            res += Double.parseDouble(operands.get(operands.size() - 1));
        else
            res -= Double.parseDouble(operands.get(operands.size() - 1));
        System.out.println(res);
    }
}