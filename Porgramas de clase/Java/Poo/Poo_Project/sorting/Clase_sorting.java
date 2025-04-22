package sorting;

public class Clase_sorting {            // Declarar la clase
    public int [] sorting(int[] arreglo) {          // Método de ordenamiento
        int n = arreglo.length;             // Obtener la longitud del arreglo
        for (int i = 0; i < n - 1; i++) {               // Bucle para recorrer el arreglo
            for (int j = 0; j < n - i - 1; j++) {       // Bucle para comparar los elementos
                if (arreglo[j] > arreglo[j + 1]) {          // Si el elemento actual es mayor que el siguiente
                    // Intercambia arreglo[j] y arreglo[j + 1]
                    int temp = arreglo[j];          // Crear una variable temporal para almacenar el valor de arreglo[j]
                    arreglo[j] = arreglo[j + 1];      // Asignar el valor de arreglo[j + 1] a arreglo[j]
                    arreglo[j + 1] = temp;        // Asignar el valor de la variable temporal a arreglo[j + 1]
                }
            }
        }
        return arreglo;         // Retornar el arreglo ordenado
    }
    public void printArray(int[] arreglo) {         // Método para imprimir el arreglo
        int n = arreglo.length; // Obtener la longitud del arreglo
        for (int i = 0; i < n; i++) {            // Bucle para recorrer el arreglo
            System.out.print(arreglo[i] + " "); // Imprimir el elemento actual
        }
        System.out.println();
    }

    public static void main(String[] args) {         // Método principal
        Clase_sorting ob = new Clase_sorting();          // Crear una instancia de la clase
        int[] arreglo = {64, 34, 25, 12, 22, 11, 90};     // Crear un arreglo desordenado
        System.out.println("Arreglo desordenado: ");      // Imprimir el mensaje
        ob.printArray(arreglo);                          // Llamar al método para imprimir el arreglo desordenado
        ob.sorting(arreglo);                             // Llamar al método de ordenamiento
        System.out.println("Arreglo ordenado: ");        // Imprimir el mensaje
        ob.printArray(arreglo);                          // Llamar al método para imprimir el arreglo ordenado
    }
}
