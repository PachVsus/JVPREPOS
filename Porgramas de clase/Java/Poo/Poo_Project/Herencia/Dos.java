package Herencia;
import static java.lang.System.out;

public class Dos extends Uno{
    static { out.println("Static Dos");}
    
    public Dos() {
        System.out.println("Constructor Dos() called");
}
}
