package test;


import java.time.LocalDate;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        System.out.println("=== CASOS MALOS (FALLIDOS) ===");

        System.out.println("\n1. Número impar como par:");
        System.out.println("¿7 es par? " + esPar(7)); // false

        System.out.println("\n2. Número no palíndromo:");
        System.out.println("¿345 es palíndromo? " + esPalindromo(345)); // false

        System.out.println("\n3. Número no múltiplo de 3 y 5:");
        System.out.println("¿10 es múltiplo de 3 y 5? " + esMultiploDe5y3(10)); // false

        System.out.println("\n4. Palabras con espacios y duplicados:");
        List<String> listaPalabras = List.of(" JAVA ", "java ", "JAVA", "Python");
        List<String> procesadas = listaPalabras.stream()
            .map(String::trim)
            .map(String::toLowerCase)
            .distinct()
            .sorted()
            .toList();
        System.out.println(procesadas);

        System.out.println("\n5. Fechas que NO son 1 de mayo:");
        List<LocalDate> dateList = List.of(
            LocalDate.of(2025, 4, 1),
            LocalDate.of(2025, 5, 2),
            LocalDate.of(2025, 6, 1),
            LocalDate.of(2024, 1, 1)
        );
        List<Integer> yearList = dateList.stream()
            .filter(d -> d.getDayOfMonth() == 1 && d.getMonthValue() == 5)
            .map(LocalDate::getYear)
            .distinct()
            .sorted()
            .toList();
        System.out.println("Años filtrados (debería estar vacío): " + yearList);
    }

    public static boolean esPar(int numero) {
        return numero % 2 == 0;
    }

    public static boolean esPalindromo(int numero) {
        String numStr = String.valueOf(numero);
        return numStr.equals(new StringBuilder(numStr).reverse().toString());
    }

    public static boolean esMultiploDe5y3(int numero) {
        return numero % 5 == 0 && numero % 3 == 0;
    }
}
