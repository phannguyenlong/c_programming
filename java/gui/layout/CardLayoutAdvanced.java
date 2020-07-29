package layout;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class CardLayoutAdvanced extends JFrame implements ActionListener {
    private static final long serialVersionUID = -9029168076322035759L;

    private Container container;
    private JPanel drop_down_container, cards_container;

    public CardLayoutAdvanced() {
        container = getContentPane();
        container.setLayout(new BoxLayout(container, BoxLayout.Y_AXIS)); // set Border layout big container

        // Header container
        container.add(new JLabel("This is demo event handler with Card Layout")); // add to Jframe
        container.add(Box.createRigidArea(new Dimension(0, 15))); // space between component

        // Handle drop down box
        drop_down_container = new JPanel(new FlowLayout()); // create Jpannel to contain dropdow component
        String[] options_list = { "Buttons", "Text" }; 
        JComboBox<String> options = new JComboBox<>(options_list); // create Dropdow component (JComboxBox)
        options.setEditable(false);
        // Add event listener to options
        options.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                System.out.println(e.getItem());
                CardLayout c1 = (CardLayout) cards_container.getLayout(); // must cast to CardLayout type
                c1.show(cards_container, (String) e.getItem());
            }
        });
        // add to ComboBox
        drop_down_container.add(options); // add ComboBox to JPannel

        container.add(drop_down_container); // add JPannel to JFrame
        container.add(Box.createRigidArea(new Dimension(0, 15))); // space between component

        // Handle Cards
        cards_container = new JPanel(new CardLayout()); // create JPannelt to hold 2 cards inside
        // card 1
        JPanel card1 = new JPanel(new FlowLayout());
        String[] buttons = { "Ok", "Cancel", "Exit" };
        for (String index : buttons) {
            JButton btn = new JButton(index);
            btn.addActionListener(this);
            card1.add(btn);
        }
        // card 2
        JPanel card2 = new JPanel(new FlowLayout());
        card2.add(new JTextField(20));
        // add 2 cards to card_container
        cards_container.add(card1, "Buttons");
        cards_container.add(card2, "Text");

        // add to JFrame
        container.add(cards_container);

        renderWindow();
    }
    
    private void renderWindow() {
        pack();
        setTitle("Card Layout Advanced");
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if ("ok".equalsIgnoreCase(e.getActionCommand()))
            JOptionPane.showMessageDialog(rootPane, "You clicked button OK");
        if ("cancel".equalsIgnoreCase(e.getActionCommand()))
            JOptionPane.showConfirmDialog(rootPane, "Are you sure want to cancel", "Cancel", JOptionPane.CANCEL_OPTION);
        if ("exit".equalsIgnoreCase(e.getActionCommand()))
            System.exit(0);
    }
    
    public static void main(String[] args) {
        new CardLayoutAdvanced();
    }
}