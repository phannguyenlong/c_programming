package calculator.action;

import java.awt.event.*;

import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

/**
 * This class will handle the event of button from MainFrame
 * 
 * @author Long Shirmp
 */
public class ButtonAction implements ActionListener {
    private JTextField monitor;

    public ButtonAction(JTextField monitor) {
        this.monitor = monitor;
    }

    private String calculate(String operate) throws ScriptException {
        // Using this to convert string to code
        ScriptEngineManager manager = new ScriptEngineManager();
        ScriptEngine engine = manager.getEngineByName("js");
        Object result = new Object();
        result = engine.eval(operate);
        return result.toString();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String action = e.getActionCommand();
        if (action == "<--") {
            String op = monitor.getText();
            op = op.length() == 0 ? op : op.substring(0, op.length() - 1);
            monitor.setText(op);
        } else if (action == "C") {
            monitor.setText("");
        } else if (action == "=") {
            try {
                monitor.setText(calculate(monitor.getText()));
            } catch (ScriptException e1) {
                showErrorMsg("Invalid operation");
            } catch (NullPointerException e1) {
                showErrorMsg("There is no operation");
            }
        } else {
            monitor.setText(monitor.getText() + action);
        }
    }
    private void showErrorMsg(String content) {
        JOptionPane.showMessageDialog(monitor, content, "Error", JOptionPane.ERROR_MESSAGE, null);
    }
}