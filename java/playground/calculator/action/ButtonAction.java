package calculator.action;

import java.awt.event.*;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

/**
 * This class will handle the event of button from MainFrame
 * @author Long Shirmp
 */
public class ButtonAction implements ActionListener {
    private JTextField monitor;

    public ButtonAction(JTextField monitor) {
        this.monitor = monitor;
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
                CalculateEngine calculator = new CalculateEngine();
                monitor.setText(calculator.calculate(monitor.getText()));
            } catch (NullPointerException e1) {
                showErrorMsg("There is no operation");
            } catch (InvalidOperationException e1) {
                showErrorMsg("Invalid Operation");
            } catch (Exception e1) {
                e1.printStackTrace();
            }
        } else {
            monitor.setText(monitor.getText() + action);
        }
    }
    private void showErrorMsg(String content) {
        JOptionPane.showMessageDialog(monitor, content, "Error", JOptionPane.ERROR_MESSAGE, null);
    }
}