package layout;

import javax.swing.*;
import java.awt.*;

public class FlowLayoutDemo {
    FlowLayoutDemo() {
        JFrame frame = new JFrame("Flow Layout Demo");
        frame.getContentPane().setLayout(new FlowLayout(1, 10, 10));
        // 1 mean left to right, 10 horizontal gap, 10 is vertical gap

        // Must be before set up frame
        frame.getContentPane().add(new JButton("Button1"));
        frame.getContentPane().add(new JButton("Button2"));
        frame.getContentPane().add(new JButton("Button3"));
        frame.getContentPane().add(new JButton("Button4"));

        //===========Set up frame =============
        frame.setSize(400, 400);
        frame.setLocationRelativeTo(null); // popup in center
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);

    }
    public static void main(String[] args) {
        new FlowLayoutDemo();
    }
}