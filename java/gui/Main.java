import javax.swing.*;
import java.awt.*;

public class Main {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Hello World"); // Crate a frame
        frame.getContentPane().setLayout(new BorderLayout());

        // ============ Add content to frame =============
        JLabel label1 = new JLabel("Hello world");
        frame.getContentPane().add(label1, BorderLayout.CENTER);
        JLabel label2 = new JLabel("Hi world");
        frame.getContentPane().add(label2, BorderLayout.LINE_END);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        // ======== Set Up Jrame ==========
        // frame.pack(); // auto matic defined size (width and heigh)
        frame.setSize(200, 200);

        frame.setLocationRelativeTo(null); // set location where JFAME appere (null to centering)
        frame.setVisible(true);
    }
}