package chap6;

import java.io.IOException;
import java.nio.file.FileSystems;
import java.nio.file.FileVisitResult;
import java.nio.file.Files;
import java.nio.file.InvalidPathException;
import java.nio.file.Path;
import java.nio.file.PathMatcher;
import java.nio.file.Paths;
import java.nio.file.SimpleFileVisitor;
import java.nio.file.attribute.BasicFileAttributes;
import java.util.Scanner;

/**
 * This is the exercise 6.4
 * Search for pdf file
 */
public class SearchFile extends SimpleFileVisitor<Path> {
    private static PathMatcher matcher;

    public SearchFile(String matcher) {
        SearchFile.matcher = FileSystems.getDefault().getPathMatcher(matcher); // ex: glob:*pdf
    }

    public static void setMatcher(String matcher) {
        SearchFile.matcher = FileSystems.getDefault().getPathMatcher(matcher); // ex: glob:*pdf
    }
    
    @Override
    public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) throws IOException {
        if (attrs.isRegularFile()) {
            if (matcher.matches(file.getFileName())) {
                System.out.println("Match: " + file);
            }
        }
        return FileVisitResult.CONTINUE;
    }

    public static void main(String[] args) {
        try (Scanner scan = new Scanner(System.in)) {
            System.out.print("Input path to search: ");
            String p = scan.nextLine();
            Path path = Paths.get(p);

            System.out.print("Input syntax to search (ex: glob:*.pdf): ");
            String matcher = scan.nextLine();

            SearchFile search = new SearchFile(matcher);
            Files.walkFileTree(path, search);

        } catch (InvalidPathException e) {
            System.out.println("Invalid Path Syntaxt");
        } catch (UnsupportedOperationException | IllegalArgumentException e) {
            System.out.println("Wrong syntaxt: " + e.getMessage());
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}