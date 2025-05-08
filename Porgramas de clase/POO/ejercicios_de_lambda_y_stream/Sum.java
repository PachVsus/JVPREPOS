package ejercicios_de_lambda_y_stream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.function.Function;
import java.util.stream.Collector;
import java.util.stream.Collectors;

interface Operacion {
    int suma(int a, int b)
}

interface Check {
    boolean check(int a, int b);
}

interface isEmpty {
    boolean isEmpty(String str);
}


public class Sum {
    public static void main(String[] args) {
        System.out.println("Probando Lambda w/Interface");
        Operacion op = (a, b) -> a + b;
        System.out.println("Suma 10 + 5: " + op.suma(10, 5));
        Check C = a -> a.isEmpty();
        System.out.println("Cadena vacia: " + C.check(""));

        // ID pares e impares
        System.out.println("\nPares");
        List<Integer> myList = Arrays.asList(10,20,3,5,30);
        List<Integer> pares = myList.stream()
                .filter(n -> n % 2 == 0)
                .collect(Collectors.toList());
        for ( Integer n : pares) {
            System.out.println(n);
        }
        System.out.println("\nImpares");
        List<Integer> impares = myList.stream()
                .filter(n -> n % 2 != 0)
                .collect(Collectors.toList());
        for ( Integer n : impares) {
            System.out.println(n);
        }
    }


}
