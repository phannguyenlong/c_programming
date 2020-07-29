package chap5;

public class InvalidAmountParamException extends Exception{
    /**
     *
     */
    private static final long serialVersionUID = 5668421363945706149L;

    InvalidAmountParamException(String msg) {
        super(msg);
    }
}