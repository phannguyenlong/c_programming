package calculator;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import calculator.action.ButtonAction;

/**
 * This program is simple calculator
 * @author Long Shrimp
 */
public class Calculator extends JFrame implements ItemListener {
    private static final long serialVersionUID = 1L;
    private Container container;
    private JPanel controlPane, displayPane, operationPane;
    private JTextField monitor;
    private JRadioButton on, off;
    private ArrayList<JButton> buttons = new ArrayList<>();

    public Calculator() {
        super("Caculator");
        container = getContentPane();
        container.setLayout(new BoxLayout(container, BoxLayout.Y_AXIS));

        renderDisplayPane();
        renderControlPane();

        container.add(displayPane);
        container.add(operationPane);
        renderWindow();

        init();
    }

    private void renderControlPane() {
        operationPane = new JPanel(new GridBagLayout());
        operationPane.setPreferredSize(new Dimension(300, 300));

        // Add buttons
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(5, 5, 5, 5);
        gbc.ipadx = 20;
        gbc.ipady = 20;

        // on/off button
        controlPane = new JPanel(new FlowLayout(1, 0, 0));
        controlPane.setPreferredSize(new Dimension(20, 30));

        on = new JRadioButton("on");
        off = new JRadioButton("off");
        // add listener
        on.addItemListener(this);
        off.addItemListener(this);
        // Group radio butotn (once is press at the time)
        ButtonGroup controlGroup = new ButtonGroup();
        controlGroup.add(on);
        controlGroup.add(off);

        controlPane.add(on);
        controlPane.add(off);

        gbc.gridx = 0;
        gbc.gridy = 0;
        operationPane.add(controlPane, gbc);

        // Numerical button
        String[][] btnValue = { { " ", "<--", "C", "+" }, { "7", "8", "9", "-" }, { "4", "5", "6", "*" },
                { "1", "2", "3", "/" }, { "0", ".", "=", "" } };
        int y = 0;
        for (String[] indexArr : btnValue) {
            int x = 0;
            for (String index : indexArr) {
                if ((x == 0 && y == 0) || (x == 3 && y == 4)) {
                    x++;
                    continue;
                }
                ;
                JButton tmp = new JButton(index);
                tmp.setFont(new Font("Arial", Font.BOLD, 12));
                tmp.addActionListener(new ButtonAction(monitor));
                buttons.add(tmp);

                gbc.gridx = x;
                gbc.gridy = y;
                if (x == 2 && y == 4) {
                    gbc.gridwidth = 2; // take 2 place
                    gbc.fill = GridBagConstraints.HORIZONTAL; // strength the button
                }
                operationPane.add(tmp, gbc);
                x++;
            }
            y++;
        }
    }

    private void renderDisplayPane() {
        displayPane = new JPanel(new FlowLayout(1, 20, 20));
        displayPane.setPreferredSize(new Dimension(300, 60));

        monitor = new JTextField();
        // Config text field apprearance
        monitor.setHorizontalAlignment(SwingConstants.RIGHT);
        monitor.setFont(new Font("Arial", Font.BOLD, 14));
        monitor.setPreferredSize(new Dimension(280, 40));
        // Add event when pressed enter
        monitor.addActionListener(new ButtonAction(monitor));
        monitor.setActionCommand("=");

        displayPane.add(monitor);
    }

    private void renderWindow() {
        pack();
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
        setResizable(false);
    }

    private void printBanner(String message) {
        char[] arr = message.toCharArray();
        monitor.setText("");
        new Thread(() -> {
            try {
                for (char c : arr) {
                    monitor.setText(monitor.getText() + c);
                    Thread.sleep(50);
                }
                monitor.setText("");
            } catch (Exception e) {
                e.printStackTrace();
            }
        }).start();
    }

    private void init() {
        on.setSelected(true);
    }

    private void changePowerStage(String state) {
        String message = state == "on" ? "======Welcome======" : "======Goodbye======";
        printBanner(message);
        for (JButton item : buttons)
            item.setEnabled(state == "on" ? true : false);
    }

    @Override
    public void itemStateChanged(ItemEvent e) {
        int state = (int) e.getStateChange();
        Object item = (Object) e.getItem();
        if (item == on && state == 1)
            changePowerStage("on");
        else if (item == off && state == 1)
            changePowerStage("off");
    }

    public static void main(String[] args) {
        new Calculator();
    }

}