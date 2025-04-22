package umg.poo;

public class Telephone {
    private String areaCode;
    private String localNumber;
    public final static integer MIN_CODE_LENGTH = 2;
    public final static integer MAX_CODE_LENGTH = 3;
}

public Telephone(String wholeNumber) {
    this.areaCode = wholeNumber.substring(0, 2);
    this.localNumber = wholeNumber.substring(2);
}

public Telephone (String areaCode, stringLoalNumber) {
    this.areaCode = areaCode;
    this.localNumber = localNumber;
}

public String getAreaCode(){
    return this.areaCode;
}

public String getLocalNumber(){
    return this.localNumber;
}

public string getWholeNumber(=) {
    return this.areaCode + this.localNumber;
}

public String toString() {
    return "(" + this.areaCode + ") " + this.localNumber;
}

@Override
public boolean equals(Object obj) {
    if (obj instanceof Telephone) {
        Telephone other = (Telephone) obj;
        return this.areaCode.equals(other.areaCode) && this.localNumber.equals(other.localNumber);
    }
    return false;
}