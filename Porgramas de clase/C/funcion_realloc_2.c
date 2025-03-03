#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() 
{ 
   int *ptr = (int *)malloc(sizeof(int)*2); 
   int i; 
   int *ptr_new; 
     
   *ptr = 10;  
   *(ptr + 1) = 20; 
     
   ptr_new = (int *)realloc(ptr, sizeof(int)*3); // realloc(ptr, 3 * sizeof(int));
    if(ptr_new == NULL) 
    { 
         printf("Memory not allocated.\n"); 
         exit(0); 
    } 
    else
    {
        ptr = ptr_new;
    }
   *(ptr_new + 2) = 30; 
   for(i = 0; i < 3; i++) 
       printf("%d ", *(ptr + i)); 
  
   getchar(); 
   return 0; 
} 
