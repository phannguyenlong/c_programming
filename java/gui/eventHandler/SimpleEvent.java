package eventHandler;

import javax.swing.*;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SimpleEvent extends JFrame implements ActionListener {
    private static final long serialVersionUID = -67923487568381348L;

    private JButton okButton, exitButton, cancelButton;

    public SimpleEvent() {
        render();
    }

    private void render() {
        okButton = new JButton("ok");
        exitButton = new JButton("exit");
        cancelButton = new JButton("cancel");
        setLayout(new FlowLayout());

        this.add(okButton);
        okButton.setActionCommand("ok"); // set action Command for this button
        okButton.addActionListener(this);

        this.add(exitButton);
        // exitButton.setActionCommand("exit");
        exitButton.addActionListener(this);

        this.add(cancelButton);
        // cancelButton.setActionCommand("cancel");
        cancelButton.addActionListener(this);

        // setSize(400, 300);
        pack();
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if ("ok".equals(e.getActionCommand())) // catch Action command
            JOptionPane.showMessageDialog(rootPane, "You just clicked button Ok");
        if ("cancel".equals(e.getActionCommand()))
            JOptionPane.showConfirmDialog(rootPane, "Are you sure want to cancel", "Cancel", JOptionPane.CANCEL_OPTION);
        if ("exit".equals(e.getActionCommand()))
            System.exit(0);
    }

    public static void main(String[] args) {
        new SimpleEvent();
    }
}