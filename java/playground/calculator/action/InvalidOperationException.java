package calculator.action;

/**
 * Check for Invalid Operation
 */
public class InvalidOperationException extends RuntimeException {
    private static final long serialVersionUID = 1L;

    public InvalidOperationException(String msg) {
        super(msg);
    }
}
