package umg.poo;

public class Telephone {
    private String areaCode;
    private String localNumber;
    public final static int MIN_CODE_LENGTH = 2;
    public final static int MAX_CODE_LENGTH = 3;

    public Telephone(String wholeNumber) {
        this.areaCode = wholeNumber.substring(0, 2);
        this.localNumber = wholeNumber.substring(2);
    }

    public Telephone(String areaCode, String localNumber) {
        this.areaCode = areaCode;
        this.localNumber = localNumber;
    }

    public String getAreaCode() {
        return this.areaCode;
    }

    public String getLocalNumber() {
        return this.localNumber;
    }

    public String getWholeNumber() {
        return this.areaCode + this.localNumber;
    }

    @Override
    public String toString() {
        return "(" + this.areaCode + ") " + this.localNumber;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Telephone other) {
            return this.areaCode.equals(other.areaCode) && this.localNumber.equals(other.localNumber);
        }
        return false;
    }

    @Override
    public int hashCode() {
        return (areaCode + localNumber).hashCode();
    }
}