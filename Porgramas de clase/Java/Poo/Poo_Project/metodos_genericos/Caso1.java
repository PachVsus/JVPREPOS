package metodos_genericos;

import java.util.*;

public class Caso1 {
    
        // Caso 1
        public static void print(List<?> list) {        // Método genérico
            for (int i = 0; i < list.size(); i++) {         // Iterador
                Object obj = list.get(i);                   // Objeto genérico
                System.out.printf("%2d) %s\n", i, obj);     // Imprime el objeto
            }
        }
    
        // Caso 2   
        public static <T> int frequency(Collection<T> collection, T object) {     // Método genérico
            int count = 0;                  // Contador
            for (T item : collection) {       // Iterador
                if (item.equals(object)) count++;   // Compara el objeto
            }
            return count;        // Devuelve el contador
        }
    
        // Caso 3
        public static int greatestInteger(Collection<Integer> collection) {       // Método genérico
            Integer max = null;           // Variable para el máximo
            for (Integer num : collection) {           // Iterador
                if (max == null || num > max) max = num;    // Compara el número
            }
            return max;          // Devuelve el máximo
        }
    
        // Caso 4
        public static double greatestNumber(Collection<Number> collection) {    // Método genérico
            Number max = null;         // Variable para el máximo
            for (Number num : collection) {          // Iterador
                if (max == null || num.doubleValue() > max.doubleValue()) max = num;    // Compara el número
            }
            return max.doubleValue();     // Devuelve el máximo
        }
    
        // Caso 5
        public static double greatestNumberGeneric(Collection<? extends Number> collection) {   // Método genérico
            Number max = null;       // Variable para el máximo
            for (Number num : collection) {         // Iterador
                if (max == null || num.doubleValue() > max.doubleValue()) max = num;    // Compara el número
            }
            return max.doubleValue();   // Devuelve el máximo
        }   
    
        // Caso 6
        public static void changeQueue(Queue<? super Number> dest, Queue<Number> src) {   // Método genérico
            while (!src.isEmpty()) {        // Iterador
                dest.offer(src.poll());      // Cambia el objeto de la cola
            }
        }
    
        // Caso 7
        public static <T> void changeQueueGeneric(Queue<? super T> dest, Queue<? extends T> src) {  // Método genérico
            while (!src.isEmpty()) {    // Iterador
                dest.offer(src.poll());     // Cambia el objeto de la cola
            }
        }
    
        public static void main(String[] args) {        // Método principal
            // Caso 1
            System.out.println("Caso 1:");
            List<String> strList = List.of("Primero", "Segundo", "Tercero");    // Lista de cadenas
            print(strList);
            System.out.println();
    
            // Caso 2
            System.out.println("Caso 2:");
            List<String> words = List.of("hola", "adiós", "hola");  // Lista de palabras
            System.out.println("Frecuencia de 'hola': " + frequency(words, "hola"));    // Frecuencia de la palabra "hola"
            System.out.println("Frecuencia de 'adiós': " + frequency(words, "adiós"));  // Frecuencia de la palabra "adiós"
            System.out.println();
    
            // Caso 3
            System.out.println("Caso 3:");  
            List<Integer> numbers = List.of(10, 50, 20, 80, 30);
            System.out.println("Mayor entero: " + greatestInteger(numbers));
            System.out.println();
    
            // Caso 4
            System.out.println("Caso 4:");
            List<Number> mixedNumbers = new ArrayList<>();
            mixedNumbers.add(10);
            mixedNumbers.add(20.5);
            mixedNumbers.add(3.14f);
            System.out.println("Mayor número (Number): " + greatestNumber(mixedNumbers));
            System.out.println();
    
            // Caso 5
            System.out.println("Caso 5:");
            List<Double> doubleList = List.of(1.2, 5.7, 3.3);
            System.out.println("Mayor número (genérico): " + greatestNumberGeneric(doubleList));
            System.out.println();
    
            // Caso 6
            System.out.println("Caso 6:");
            Queue<Number> numberQueue = new ArrayDeque<>();
            numberQueue.offer(100);
            numberQueue.offer(35.5);
            Queue<Object> objectQueue = new ArrayDeque<>();
            objectQueue.offer("Hola");
            changeQueue(objectQueue, numberQueue);
            System.out.println("Cola destino después de changeQueue: " + objectQueue);
            System.out.println();
    
            // Caso 7
            System.out.println("Caso 7:");
            Queue<Integer> intQueue = new ArrayDeque<>();
            intQueue.offer(1);
            intQueue.offer(2);
            Queue<Number> numQueue = new ArrayDeque<>();
            changeQueueGeneric(numQueue, intQueue);
            System.out.println("Cola destino después de changeQueueGeneric: " + numQueue);
        }
    }
    

