#include <stdio.h>
#include <stdlib.h>
#pragma pack ( 1 ) // 1 byte alignment

/*En el siguiente ejemplo, mediante el uso
de la directiva pragma de preprocesamiento
forzamos a que la alineación de datos dentro
de las estructuras de sujeta a un 1 byte.*/

 int main(void) {
        struct gif_hdr
        {
                char signature[3];
                char version[3];
                int width;
                int height;
                char colormap;
                char bgcolor;
                char ratio;
        };
        struct gif_hdr v1;
        struct gif_hdr *dsptr;
        printf("Size of structure data = %d\n", sizeof(struct gif_hdr));
        dsptr = (struct gif_hdr*)malloc(sizeof(struct gif_hdr));
        printf("Offset of signature = %d\n", &(dsptr->signature[0]) - &(dsptr->signature[0]) );
        printf("Offset of version = %d\n", &(dsptr->version[0]) - &(dsptr->signature[0]) );
        printf("Offset of width = %d\n", (char*)&(dsptr->width) - &(dsptr->signature[0]));
        printf("Offset of height = %d\n", (char*)&(dsptr->height) - &(dsptr->signature[0]));
        printf("Offset of colormap = %d\n", &(dsptr->colormap) - &(dsptr->signature[0]));
        printf("Offset of bgcolor = %d\n",&(dsptr->bgcolor) - &(dsptr->signature[0]));
        printf("Offset of ratio = %d\n", &(dsptr->ratio) - &(dsptr->signature[0]));

        free(dsptr);

        return 0;
 }