package filesearch.action;

import java.io.File;
import java.io.IOException;
import java.nio.file.FileSystems;
import java.nio.file.FileVisitResult;
import java.nio.file.Path;
import java.nio.file.PathMatcher;
import java.nio.file.SimpleFileVisitor;
import java.nio.file.attribute.BasicFileAttributes;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

import javax.swing.table.DefaultTableModel;

public class SearchFile extends SimpleFileVisitor<Path> {
    private static PathMatcher matcher;
    protected DefaultTableModel model;

    public SearchFile(String matcher, DefaultTableModel model) {
        SearchFile.matcher = FileSystems.getDefault().getPathMatcher(matcher);
        this.model = model;
    }

    @Override
    public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) throws IOException {
        if (attrs.isRegularFile()) {
            if (matcher.matches(file.getFileName())) {
                System.out.println("Match: " + file);
                File f = new File(file.toString());
                
                String fExten = file.toString().substring(file.toString().lastIndexOf("."));

                Date date = new Date(f.lastModified());
                DateFormat df = new SimpleDateFormat("HH:mm dd/MM/yy");
                
                model.addRow(new Object[] { file, f.length(), fExten, df.format(date)});
            }
        }
        return FileVisitResult.CONTINUE;
    }
}