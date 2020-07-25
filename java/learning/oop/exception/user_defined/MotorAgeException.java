package exception.user_defined;

/**
 * This is demo of Checked Exception (extends Exception)
 */
public class MotorAgeException extends Exception{
    /**
     *id 
     */
    private static final long serialVersionUID = 1L;

    MotorAgeException(String msg) {
        super(msg);
    }

    MotorAgeException() {
    }

    @Override
    public String getMessage() {
        return super.getMessage();
    }
}