package umg.poo;

public class Workphone extends Telephone {
    protected int countryCode;
    private int extension = 0;
    public final static int MIN_CODE_LENGTH = 0;
    public final static int MAX_CODE_LENGTH = 1000;

    public Workphone(String wholeNumber, int extension, int countryCode) {
        super(wholeNumber);
        this.extension = extension;
        this.countryCode = countryCode;
    }
    public Workphone(int Telephone telephone)
}
