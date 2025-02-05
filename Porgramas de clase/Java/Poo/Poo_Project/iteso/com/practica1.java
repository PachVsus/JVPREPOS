import java.util.Scanner;


public class practica1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Introduce una palabra:");
        String palabra = scanner.nextLine();
        String palabraInvertida = new StringBuilder(palabra).reverse().toString();

        if (palabra.equalsIgnoreCase(palabraInvertida)) {
            System.out.println("La palabra es un palíndromo.");
        } else {
            System.out.println("La palabra no es un palíndromo.");
        }
        scanner.close();
        }
        
    }