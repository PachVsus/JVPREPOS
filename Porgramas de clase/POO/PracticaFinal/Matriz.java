package PracticaFinal;
public class Matriz {



    
    
    
    static void crearMatriz(int[] intArray) {
        boolean[][]matriz=new boolean[intArray.length] [];
        int F = intArray.length;
        System.out.println("Filas: " + F);
        for(int i=0; i< intArray.length; i++){
            matriz[i]=new boolean[intArray[i]];
            System.out.println("Columnas: " + intArray[i]);
        }
        // Imprimir la matriz
        System.out.println(Arrays.deepToString(matriz));
        }
        public static void main(String[] args) {
            int[] myArray = {3, 4, 2, 5};  
            crearMatriz(myArray);
            
        }
    }
