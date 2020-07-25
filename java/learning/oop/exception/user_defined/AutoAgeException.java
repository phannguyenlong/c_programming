package exception.user_defined;

/**
 * This is the Unchecked Exception (extends RuntimeException)
 */
public class AutoAgeException extends RuntimeException {
    /**
     *
     */
    private static final long serialVersionUID = 1L;

    AutoAgeException(String msg) {
        super(msg);
    }

    @Override
    public String getMessage() {
        return super.getMessage();
    }
}