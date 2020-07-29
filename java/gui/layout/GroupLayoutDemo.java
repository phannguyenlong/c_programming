package layout;

import javax.swing.*;
import java.awt.*;

public class GroupLayoutDemo extends JFrame {
    private static final long serialVersionUID = 5117972416527264568L;

    private Container container;

    public GroupLayoutDemo() {
        super("Group Layout demo");
        container = getContentPane();

        JPanel panel = new JPanel();
        panel.setBackground(Color.cyan);
        panel.setSize(200, 200);
        GroupLayout layout = new GroupLayout(panel);
        layout.setAutoCreateGaps(true);
        layout.setAutoCreateContainerGaps(true);
        JButton btn1 = new JButton("Button 1");
        JButton btn2 = new JButton("Button 2");
        JButton btn3 = new JButton("Button 3");

        layout.setHorizontalGroup(layout.createSequentialGroup().addComponent(btn1)
                .addGroup(layout.createSequentialGroup().addGroup(layout
                        .createParallelGroup(GroupLayout.Alignment.LEADING).addComponent(btn2).addComponent(btn3))));

        layout.setVerticalGroup(
                layout.createSequentialGroup().addComponent(btn1).addComponent(btn2).addComponent(btn3));
        panel.setLayout(layout);

        container.add(panel);
        renderWindow();
    }

    public void renderWindow() {
        setSize(400, 400);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public static void main(String[] args) {
        new GroupLayoutDemo();
    }
}