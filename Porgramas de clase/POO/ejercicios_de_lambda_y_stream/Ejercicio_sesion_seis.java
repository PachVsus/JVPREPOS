package ejercicios_de_lamba_y_stream;

import java.util.*;
import java.util.function.*;
import java.util.stream.*;

public class Ejercicio_sesion_seis {

    // Parte 1: Lambdas y Streams

    // Lambda para sumar dos enteros
    static BinaryOperator<Integer> sumar = (a, b) -> a + b;

    // Lambda para verificar si un String está vacío
    static Predicate<String> estaVacio = s -> s.isEmpty();

    // Lambda para verificar si un número es par
    static Predicate<Integer> esPar = n -> n % 2 == 0;

    // Stream para obtener máxima y mínima longitud de strings
    public static void longitudMinMax(List<String> lista) {
        OptionalInt max = lista.stream().mapToInt(String::length).max();
        OptionalInt min = lista.stream().mapToInt(String::length).min();

        max.ifPresent(m -> System.out.println("Máxima longitud: " + m));
        min.ifPresent(m -> System.out.println("Mínima longitud: " + m));
    }

    // Parte 2: Construir matriz con booleanos
    public static void construirMatriz(int[] intArray) {
        boolean[][] matriz = new boolean[intArray.length][];
        for (int i = 0; i < intArray.length; i++) {
            matriz[i] = new boolean[intArray[i]];
            Arrays.fill(matriz[i], true);
        }

        // Imprimir matriz con un solo for-each
        for (boolean[] fila : matriz) {
            for (boolean val : fila) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }

    // Parte 3: Procesar matriz y transponerla
    public static void procesarMatriz(int[][] matriz) {
        System.out.println("Matriz original:");
        imprimirMatriz(matriz);

        int filas = matriz.length;
        int columnas = matriz[0].length;

        int[][] transpuesta = new int[columnas][filas];

        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                transpuesta[j][i] = matriz[i][j];
            }
        }

        System.out.println("\nMatriz transpuesta:");
        imprimirMatriz(transpuesta);
    }

    // Método auxiliar para imprimir cualquier matriz
    public static void imprimirMatriz(int[][] matriz) {
        for (int[] fila : matriz) {
            for (int val : fila) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }

    // Método main para probar todo
    public static void main(String[] args) {

        // Parte 1: Lambdas
        System.out.println("Suma (5 + 3): " + sumar.apply(5, 3));
        System.out.println("¿Cadena vacía (''): " + estaVacio.test(""));
        System.out.println("¿Es 4 par?: " + esPar.test(4));
        longitudMinMax(Arrays.asList("Hola", "Mundo", "Java", "Stream"));

        // Parte 2: Matriz a partir de arreglo
        System.out.println("\nMatriz booleana generada:");
        construirMatriz(new int[]{3, 5, 2});

        // Parte 3: Transposición de matriz
        int[][] ejemploMatriz = {
            {4, 2, 3},
            {7, 0, 1},
            {1, 6, 2},
            {3, 9, 6},
            {5, 7, 4}
        };
        System.out.println("\nTransposición de matriz:");
        procesarMatriz(ejemploMatriz);
    }
}
