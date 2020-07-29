package layout;

import javax.swing.*;
import java.awt.*;

public class GridBagLayoutDemo extends JFrame {
    private static final long serialVersionUID = -2170628724774568631L;
    private Container container;

    public GridBagLayoutDemo() {
        super("GridBag Layout Demo");
        container = getContentPane();
        container.setLayout(new FlowLayout());

        JPanel panel = new JPanel();
        panel.setLayout(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();

        gbc.insets = new Insets(5, 5, 5, 5); // to set space bewtween (padding)

        gbc.gridx = 0; // x to set position x
        gbc.gridy = 0; // y to set position y
        panel.add(new JButton("Button 1"), gbc);

        gbc.gridx = 1;
        gbc.gridy = 0;
        panel.add(new JButton("Button 2"), gbc);

        gbc.ipady = 20; // to set the height (y) of component
        gbc.gridx = 0;
        gbc.gridy = 1;
        panel.add(new JButton("Button 3"), gbc);

        gbc.gridx = 1; 
        gbc.gridy = 1;
        panel.add(new JButton("Button 4"), gbc);

        gbc.ipady = 40;
        gbc.gridx = 0;
        gbc.gridy = 2;
        gbc.fill = GridBagConstraints.HORIZONTAL; // To fill all space left in horizontal
        gbc.gridwidth = 2;
        panel.add(new JButton("Button 5"), gbc);

        container.add(panel);

        renderWindow();
    }

    public void renderWindow() {
        setSize(300, 300);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public static void main(String[] args) {
        new GridBagLayoutDemo();
    }
}