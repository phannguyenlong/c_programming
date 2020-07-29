package eventHandler.simple_calculator;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class SimpleCalculator extends JFrame implements ActionListener, ItemListener {
    private static final long serialVersionUID = -7578047298422483183L;

    private Container container;
    private JPanel choiceContainer, operationContainer;
    private JRadioButton plus, minus;
    private JTextField input1, input2;
    private JLabel sign, equal, res;
    private JButton cal_btn;

    public SimpleCalculator() {
        super("Simple Calculator");
        container = getContentPane();
        container.setLayout(new BorderLayout());

        // Choice button Container
        choiceContainer = new JPanel(new FlowLayout());
        plus = new JRadioButton("plus");
        minus = new JRadioButton("minus");
        ButtonGroup choiceGroup = new ButtonGroup(); // using button group to choose 1 choice 1 time only
        plus.addItemListener(this);
        minus.addItemListener(this);
        // Add to Button Group
        choiceGroup.add(plus);
        choiceGroup.add(minus);
        // Add to choiceContainer
        choiceContainer.add(plus);
        choiceContainer.add(minus);

        // Operation Container
        operationContainer = new JPanel(new FlowLayout());
        input1 = new JTextField(10); // size for input
        input2 = new JTextField(10);
        sign = new JLabel("?");
        equal = new JLabel("=");
        res = new JLabel("?");
        // Add to JPannel container
        operationContainer.add(input1);
        operationContainer.add(sign);
        operationContainer.add(input2);
        operationContainer.add(equal);
        operationContainer.add(res);

        // Calculate Button
        cal_btn = new JButton("Calculate");
        cal_btn.addActionListener(new ButtonAction());

        container.add(choiceContainer, BorderLayout.LINE_START);
        container.add(operationContainer, BorderLayout.CENTER);
        container.add(cal_btn, BorderLayout.PAGE_END);

        renderWindow();
    }

    private void renderWindow() {
        // pack();
        setSize(500, 100);
        setLocationRelativeTo(null);
        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    // There is 2 way of implement eventn listener
    // 1 is from Implements them orrivde
    // 2 is create a new class inside it that extends AstractAction
    
    // ================METHOD1======================
    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getActionCommand().equalsIgnoreCase("calculate")) {
            try {
                Double x = Double.parseDouble(input1.getText());
                Double y = Double.parseDouble(input2.getText());
                if (plus.isSelected()) {
                    res.setText(String.valueOf(x + y));
                } else if (minus.isSelected()) {
                    res.setText(String.valueOf(x - y));
                } 
                System.out.println(res.getText());
            } catch (NumberFormatException except) {
                JOptionPane.showMessageDialog(container, "Input must be a number and not empty", "Error",
                        JOptionPane.ERROR_MESSAGE, null);
            }
        }
    }

    @Override
    public void itemStateChanged(ItemEvent e) {
        Object select_item = e.getItem(); // cause this radibox button ==> return an object not a string
        if (select_item == minus)
            sign.setText("-");
        else if (select_item == plus) {
            sign.setText("+");
        }
        if (!input1.getText().equals("") && !input2.getText().equals(""))
            cal_btn.doClick(); // Recalculate whenere change the operation
    }

    // ================METHOD2======================
    private class ButtonAction extends AbstractAction {
        private static final long serialVersionUID = 8239805153160482642L;

        @Override
        public void actionPerformed(ActionEvent e) {
            if (e.getActionCommand().equalsIgnoreCase("calculate")) {
                try {
                    Double x = Double.parseDouble(input1.getText());
                    Double y = Double.parseDouble(input2.getText());
                    if (plus.isSelected()) {
                        res.setText(String.valueOf(x + y));
                    } else if (minus.isSelected()) {
                        res.setText(String.valueOf(x - y));
                    }
                    System.out.println(res.getText());
                } catch (NumberFormatException except) {
                    JOptionPane.showMessageDialog(container, "Input must be a number and not empty", "Error",
                            JOptionPane.ERROR_MESSAGE, null);
                }
            }
        }

    }

    public static void main(String[] args) {
        new SimpleCalculator();
    }
}