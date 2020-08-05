package calculator.action;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;

/**
 * This class will perform a calculation with one line operation input
 * @author Long Shirmp
 * @version 1.0
 */
public class CalculateEngine {

    public CalculateEngine() {}
    /**
     * This function will convert opertation into code and calculate usign Script Engine
     * @deprecated should not use this (no security and slow)
     * @param operate
     * @return a result convert to string
     * @throws ScriptException
     */
    public String calculateScriptEngine(String operate) throws ScriptException {
        // Using this to convert string to code
        ScriptEngineManager manager = new ScriptEngineManager();
        ScriptEngine engine = manager.getEngineByName("js");
        Object result = new Object();
        result = engine.eval(operate);
        return result.toString();
    }

    /**
     * This is the algorithm parse the operation into array and calulate them
     * @param op one line operation
     * @return A result convert to string
     */
    public String calculate(String op) {
        double res = 0;
        String[] opLookup = { "+", "-", "/", "*" };
        // Extract number
        List<String> operands = Arrays.asList(op.split("[\\+\\-\\*\\/]"));
        ArrayList<String> operations = new ArrayList<>();
        // Extact + - * / operation
        Pattern pattern = Pattern.compile("[^0-9]");
        Matcher matcher = pattern.matcher(op);
        while (matcher.find()) {
            operations.add(new String(op.substring(matcher.start(), matcher.end())));
        }
        if ((operations.size() + 1) != operands.size())
            throw new InvalidOperationException("Invid operation syntax");

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
        // Add the last number
        if (prevIndex.equals("+"))
            res += Double.parseDouble(operands.get(operands.size() - 1));
        else
            res -= Double.parseDouble(operands.get(operands.size() - 1));
        return String.valueOf(res);
    }
}