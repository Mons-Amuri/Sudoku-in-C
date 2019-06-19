#include <stdio.h>
#include <string.h>

void yildizlari_yaz(int sayi)
/*****************/
{/* Bir yıldızların dizisi yazar */
    int i;
    for (i = 1; i <= sayi; i++) {
        printf("*");
    }
    printf("\n");
}/* end yildizlari_yaz */
