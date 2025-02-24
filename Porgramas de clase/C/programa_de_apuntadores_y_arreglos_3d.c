// Programa que muestra, mediante aritmética de apuntadores, la estructura de un arreglo tridimensional.

#include <stdio.h>

int main(void) {
   int data[3][3][3];   // declarar un arreglo tridimensional
   int i, j, k;         // declarar contadores
   int count = 0;       // declarar contador de elementos

   for(i = 0; i < 3; i++) {                 // recorrer la primera dimensión
       for(j = 0; j < 3; j++) {             // recorrer la segunda dimensión
           for(k = 0; k < 3; k++) {         // recorrer la tercera dimensión
               data[i][j][k] = count++;     // asignar un valor al elemento actual
           }                        // fin de recorrer la tercera dimensión
       }                   // fin de recorrer la segunda dimensión
   }              // fin de recorrer la primera dimensión   

   for(i = 0; i < 3; i++) {             // recorrer la primera dimensión
       for(j = 0; j < 3; j++) {         // recorrer la segunda dimensión
           for(k = 0; k < 3; k++) {     // recorrer la tercera dimensión
               printf("(%d, %d, %d) = %d addr %p ", i,j,k, data[i][j][k],&data[i][j][k]);       // imprimir el valor del elemento actual
           }              // fin de recorrer la tercera dimensión
           printf("\n");    
       }
       printf("\n");
   }

   for(i = 0; i < 3; i++) {                         // recorrer la primera dimensión
       printf("Capa %d addr = %p\n", i, data[i]);   // imprimir la dirección de la capa actual
   }        // fin de recorrer la primera dimensión

   printf("\n");            // imprimir un salto de línea
   for(i = 0; i < 3; i++) {                // recorrer la primera dimensión
       printf("Capa 0, Fila %d addr = %p\n", i, data[0][i]);        // imprimir la dirección de la fila actual
   }

   printf("\n");        // imprimir un salto de línea
   for(i = 0; i < 3; i++) {         // recorrer la primera dimensión
       printf("Capa 0, Fila 0, Columna %d addr = %p\n", i, &data[0][0][i]);         // imprimir la dirección del elemento actual
   }

   printf("\n2D rows addresses\n");         // imprimir un mensaje
   for(i = 0; i < 3; i++) {                 // recorrer la primera dimensión
       printf("3D %d Layer\n", i);          // imprimir el número de capa
       for(j = 0; j<3; j++) {               // recorrer la segunda dimensión
           printf("2D row %d addr = %p content = %p \n",j, data[i][j], *(data[i] + j));     // imprimir la dirección de la fila actual
       }      // fin de recorrer la segunda dimensión
   }     // fin de recorrer la primera dimensión
   return 0;
}
