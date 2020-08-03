import java.io.IOException;
import java.nio.file.FileSystems;
import java.nio.file.FileVisitResult;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.PathMatcher;
import java.nio.file.Paths;
import java.nio.file.SimpleFileVisitor;
import java.nio.file.attribute.BasicFileAttributes;
import java.util.Scanner;

public class SearchFile extends SimpleFileVisitor<Path> {
    private static final PathMatcher matcher = FileSystems.getDefault().getPathMatcher("glob:*.pdf");

    @Override
    public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) throws IOException {
        if (attrs.isRegularFile()) {
            if (matcher.matches(file.getFileName())) {
                System.out.println("Match: " + file.getFileName());
            }
        }
        return FileVisitResult.CONTINUE;
    }

    public static void main(String[] args) {
        try (Scanner scan = new Scanner(System.in)) {
            System.out.print("Input path to search: ");
            String p = scan.nextLine();
            Path path = Paths.get(p);
            
            SearchFile search = new SearchFile();
            Files.walkFileTree(path, search);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}