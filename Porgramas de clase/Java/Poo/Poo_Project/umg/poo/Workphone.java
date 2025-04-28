package umg.poo;

// Ensure the Telephone class is properly imported or defined in the same package
public class Workphone extends Telephone {
    protected int countryCode;
    private int extension;
    public final static int MIN_CODE_LENGTH = 0;
    public final static int MAX_CODE_LENGTH = 1000;

    public Workphone(String wholeNumber, int extension, int countryCode) {
        super(wholeNumber);
        this.extension = extension;
        this.countryCode = countryCode;
    }

    // Corrected constructor syntax
    public Workphone(Telephone telephone) {
        super(telephone.getWholeNumber()); // Assuming Telephone has a getWholeNumber method
    }
}

