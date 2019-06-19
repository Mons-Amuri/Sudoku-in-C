#include <stdio.h>
#include <string.h>
#define MIN 3
#define MAX 9
#define YANLIS 0
#define DOGRU 1
#include "main.h"
char matris[MAX][MAX];

/*********************/
int MatrisGirisi_kontrolEt(void)
/*********************/
{ /* matris içinde tekrarlanan rakamlar olup olmadığını kontrol eder */
    int sonuc = DOGRU;
    if (! Satirlari_kontrolEt()) sonuc = YANLIS;
    if (! Sutunlari_kontrolEt()) sonuc = YANLIS;
    if (! Kareleri_kontrolEt()) sonuc = YANLIS;
    return sonuc;
}/* end MatrisGirisi_kontrolEt */

/*********************/
int Satirlari_kontrolEt(void)
/*********************/
{/* satırlarda tekrarlanan rakamlar olup olmadığını kontrol eder */
    int satir;
    int sonuc = DOGRU;
    for (satir = 0; satir < MAX; satir++) {
        if (! SatirGirisi_kontrolEt(satir)) sonuc = YANLIS;
    }/* end for */
    return sonuc;
}/* end Satirlari_kontrolEt */

/************************/
int SatirGirisi_kontrolEt(int satir)
/************************/
{/* bir satırda tekrarlanan rakamlar olup olmadığını kontrol eder */
    int i,j;
    for (i = 0; i < MAX-1; i++) {
        if ( matris[satir][i] == 0 ) continue;
        for (j = i+1; j < MAX; j++) {
            if (matris[satir][i] == matris[satir][j]) {
                printf("HATA! SATIR %d : TEKRARLANAN RAKAMLAR\n", satir+1);
                return YANLIS;
           }/* end if */
        }/* end for j */
    }/* end for i */
    return DOGRU;
}/* end SatirGirisi_kontrolEt */

/***********************/
int Sutunlari_kontrolEt(void)
/***********************/
{/* sutunlarda tekrarlanan rakamlar olup olmadığını kontrol eder */
    int sutun;
    int sonuc = DOGRU;
    for (sutun = 0; sutun < MAX; sutun++) {
        if (! SutunGirisi_kontrolEt(sutun)) sonuc = YANLIS;
    }/* end for */
    return sonuc;
}/* end Sutunlari_kontrolEt */

/**************************/
int SutunGirisi_kontrolEt(int sutun)
/**************************/
{/* bir sutunda tekrarlanan rakamlar olup olmadığını kontrol eder */
    int i, j;
    for (i = 0; i < MAX-1; i++) {
        if ( matris[i][sutun] == 0 ) continue;
        for (j = i+1; j < MAX; j++) {
            if (matris[i][sutun] == matris[j][sutun]) {
                printf("HATA! SUTUN %d : TEKRARLANAN RAKAMLAR\n", sutun+1);
                return YANLIS;
            }/* end if */
        }/* end for j */
    }/* end for i */
    return DOGRU;
}/* end SutunGirisi_kontrolEt */

/*********************/
int Kareleri_kontrolEt(void)
/*********************/
{/* 3X3'lik karelerinde tekrarlanan rakamlar olup olmadığını kontrol eder */
    int kare;
    int sonuc = DOGRU;
    for (kare = 0; kare < MAX; kare++) {
        if (! KareGirisi_kontrolEt(kare)) sonuc = YANLIS;
    }/* end for */
    return sonuc;
}/* end Kareleri_kontrolEt */

/***********************/
int KareGirisi_kontrolEt(int kare)
/***********************/
{/* bir 3 X 3'lik karesinde tekrarlanan rakamlar olup olmadığını kontrol eder */
    char tamp[MAX];
    int i,j;
    Kare_cevirme(tamp, kare);
    for (i = 0; i < MAX-1; i++) {
        if (tamp[i] == 0 ) continue;
        for (j = i+1; j < MAX; j++) {
            if (tamp[i] == tamp[j]) {
                printf("HATA! KARE %d : TEKRARLANAN RAKAMLAR\n", kare+1);
                return YANLIS;
            }/* end if */
        }/* end for j */
    }/* end for i */
    return DOGRU;
}/* end KareGirisi_kontrolEt */
