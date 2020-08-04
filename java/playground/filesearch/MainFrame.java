package filesearch;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.event.*;
import java.nio.file.Files;
import java.nio.file.InvalidPathException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.awt.*;

import filesearch.action.SearchFile;

public class MainFrame extends JFrame implements ActionListener {
    private static final long serialVersionUID = 1L;
    protected Container container;
    protected JPanel header, body, searchBar;
    protected JTextField pathSearch, globSearch;
    protected JButton searchBtn;
    protected JTable table;
    protected DefaultTableModel model;

    public MainFrame() {
        super("File Search");
        container = getContentPane();
        container.setLayout(new BoxLayout(container, BoxLayout.Y_AXIS));

        genertateHeader();
        generateBody();

        container.add(header);
        container.add(body);
        renderWindow();
    }

    private void genertateHeader() {
        header = new JPanel(new FlowLayout(1, 10, 10));
        searchBtn = new JButton("Search");
        searchBtn.addActionListener(this);

        searchBar = new JPanel(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(5, 5, 5, 5);

        pathSearch = new JTextField(40);
        pathSearch.setBackground(Color.LIGHT_GRAY);
        pathSearch.addActionListener(this); // add listener when press Enter
        globSearch = new JTextField(40);
        globSearch.setBackground(Color.LIGHT_GRAY);
        globSearch.addActionListener(this); // add listener when press Enter

        gbc.gridx = 0;
        gbc.gridy = 0;
        searchBar.add(new JLabel("Path: "), gbc);
        gbc.gridx = 1;
        gbc.gridy = 0;
        searchBar.add(pathSearch, gbc);
        gbc.gridx = 0;
        gbc.gridy = 1;
        searchBar.add(new JLabel("Glob:"), gbc);
        gbc.gridx = 1;
        gbc.gridy = 1;
        searchBar.add(globSearch, gbc);

        header.add(searchBar);
        header.add(searchBtn);
        header.setBackground(Color.white);
    }

    private void generateBody() {
        body = new JPanel();

        // Table
        String[] titles = { "Name", "Size (Bytes)", "Type", "Modified Date" };
        table = new JTable();
        model = (DefaultTableModel) table.getModel();
        for (String index : titles)
            model.addColumn(index);

        table.getColumnModel().getColumn(0).setPreferredWidth(400); // set 1s column size
        table.setEnabled(false); // disable edit for table

        JScrollPane sp = new JScrollPane(table);
        sp.setPreferredSize(new Dimension(700, 400));
        body.add(sp);
        body.setBackground(Color.white);
    }

    private void renderWindow() {
        // setSize(700, 500);
        pack();
        setLocationRelativeTo(null);
        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (pathSearch.getText().equals("")) {
            showErrorMsg("Path must not be Empty");
        } else {
            model.setRowCount(0); // Clear table
            Path path = Paths.get(pathSearch.getText());
            String glob = globSearch.getText().equals("") ? "*" : globSearch.getText();

            // Start a thread
            Thread searchThread = new Thread(new Runnable() {
                @Override
                public void run() {
                    try {
                        SearchFile search = new SearchFile("glob:" + glob, model);
                        Files.walkFileTree(path, search);
                    } catch (InvalidPathException ex) {
                        showErrorMsg("Invalid Path Syntax");
                    } catch (UnsupportedOperationException | IllegalArgumentException ex) {
                        showErrorMsg("Wrong syntax\nEx: glob:*.pdf");
                    } catch (Exception ex) {
                        ex.printStackTrace();
                        showErrorMsg("Failed to search");
                    }
                }
            });
            searchThread.start();
        }
    }

    private void showErrorMsg(String content) {
        JOptionPane.showMessageDialog(container, content, "Error", JOptionPane.ERROR_MESSAGE, null);
    }

    public static void main(String[] args) {
        new MainFrame();
    }
}