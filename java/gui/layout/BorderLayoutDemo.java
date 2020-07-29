package layout;

import javax.swing.*;
import java.awt.*;

public class BorderLayoutDemo {
    BorderLayoutDemo() {
        JFrame frame = new JFrame("BorderLayout Demo");
        frame.getContentPane().setLayout(new BorderLayout());

        JButton btn1 = new JButton("North");
        JButton btn2 = new JButton("South");
        JButton btn3 = new JButton("West");
        JButton btn4 = new JButton("East");
        JButton btn5 = new JButton("Center");

        btn1.setPreferredSize(new Dimension(-1, 22));

        frame.getContentPane().add(btn1, BorderLayout.NORTH);
        frame.getContentPane().add(btn2, BorderLayout.SOUTH);
        frame.getContentPane().add(btn3, BorderLayout.WEST);
        frame.getContentPane().add(btn4, BorderLayout.EAST);
        frame.getContentPane().add(btn5, BorderLayout.CENTER);

        // ======== Set Up Jrame ==========
        // frame.pack(); // auto matic defined size (width and heigh)
        frame.setSize(500, 500);
        frame.setLocationRelativeTo(null); // set location where JFAME appere (null to centering)
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        new BorderLayoutDemo();
    }
}