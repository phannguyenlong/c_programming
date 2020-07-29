package layout;

import javax.swing.*;

public class BoxLayoutDemo extends JFrame{
    private static final long serialVersionUID = 1L; // for not warning only

    public BoxLayoutDemo() {
        renderLayout();
        renderWindow();
    }
    
    private void renderWindow() {
        // cause it inherit from JFrame class so dont need to create object JFrame
        setTitle("Box Layout Demo");
        setSize(400, 400);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    private void renderLayout() {
        setLayout(new BoxLayout(this.getContentPane(), BoxLayout.Y_AXIS));
        this.add(new JButton("Btn1"));
        this.add(new JButton("Btn2"));
        this.add(new JButton("Btn3"));
        this.add(new JButton("Btn4"));
    }
    public static void main(String[] args) {
        new BoxLayoutDemo();
    }
}