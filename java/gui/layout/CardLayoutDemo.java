package layout;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class CardLayoutDemo extends JFrame implements ActionListener {
    private static final long serialVersionUID = 4193563502654887367L;
    
    private Container container;
    private CardLayout card;
    private JButton btn1, btn2, btn3;

    public CardLayoutDemo() {
        renderLayout();
        renderWindow();
    }

    private void renderLayout() {
        container = getContentPane();
        card = new CardLayout(40, 30); // create card with size 40 x 30 
        container.setLayout(card);

        btn1 = new JButton("Apple");
        btn1.addActionListener(this);

        btn2 = new JButton("Banana");
        btn2.addActionListener(this);

        btn3 = new JButton("Cat");
        btn3.addActionListener(this);

        container.add("apple", btn1);
        container.add("banana", btn2);
        container.add("cat", btn3);
    }

    private void renderWindow() {
        setTitle("Card Layout Demo");
        setSize(400, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        card.next(container);
    }
    public static void main(String[] args) {
        new CardLayoutDemo();
    }

}