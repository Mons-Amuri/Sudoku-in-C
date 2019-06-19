#include <stdio.h>
#define MIN 3
#define MAX 9
#define YANLIS 0
#define DOGRU 1
#include "main.h"
char matris[MAX][MAX];
/******AMURI BINAMAN SUDOKU*******/
int main(int argc, char *argv[])
/******/
{
  printf("\n***********************************************************************\n");
  printf("|*********| |**|    |**| |********    |*******| |**|  /**/  |**|   |**|\n");
  printf("|**|******  |**|    |**| |******|**|  |*******| |**| /**/   |**|   |**|\n");
  printf("|**|______  |**|    |**| |*|    |**|  |*|   |*| |**|/**/    |**|   |**|\n");
  printf(" *********| |**|    |**| |*|    |**|  |*|   |*| |** **/___  |**|   |**|\n");
  printf("       |**| |**|    |**| |*|    |**|  |*|   |*| |**|******| |**|   |**|\n");
  printf("|*********| |** **** **| |******* /   |*******| |**|   |**| |*********|\n");
  printf("|*********| | *********| |********    |*******| |**|   |**| |*********|\n");
  printf("***********************************************************************\n\n\n");

   /**********/
   printf("%d SUTUNLU %d SUDOKU SATIRINIZI GIRINIZ,\n", MAX, MAX);
   printf("RAKAMLAR ARASINDA HERHANGI BIR KARAKTER GIREBILIRSINIZ\n");
   printf("BOSLUK ICIN 0 GIRINIZ.\n");
   printf("CIKIS YAPMAK ICIN C'YA BASINIZ\n\n");
   while (MatrisGirisi()) {
        Sudokuyu_coz();
        printf("\n                 COZULMUS SUDOKUNUZ      \n\n");
        Matrisi_yaz();
        if (! BitmisMatris()) printf("YANLIS VERILERI GIRDINIZ...\n");
    }/* end while */
    printf("\n");
    return 0;
}

/**********************************/
/**** BILGI GIRISI VE KONTROL ETME ****/
/**********************************/

/***************/
int MatrisGirisi(void)
/***************/
{
    int satir;
    printf("SUDOKU MATRISINIZI GIRINIZ : \n");
    while (DOGRU){
        for (satir = 0; satir < MAX; satir++){
         if (! SatirGirisi(satir)) return (YANLIS);
        }/* end for */
        printf("\n***********************************************************************\n");
        printf("\n                    GIRDIGINIZ VERILERI   \n\n");
        Matrisi_yaz();
        printf("\n***********************************************************************\n");
        if (MatrisGirisi_kontrolEt()) return(DOGRU);
        else printf("YANLIS VERILERI GIRDINIZ...\n");

    }/* end while */
}/* end matrisGirisi girişi */

/******************/
int SatirGirisi(int satir)
/******************/
{
    int veri, i;
    int sutun = 0;
    int sonuc = DOGRU;
    for (i = 0; i < MAX; i++) {
        matris[satir][i] = 0;
    }/* for */
    /*******/
    printf("SATIR %d : ", satir+1);
    while(DOGRU){
        veri =fgetc(stdin);
        if (veri == feof(stdin) || veri == 0x0A) return sonuc;
        else if ((veri == 'C') || (veri == 'c')) sonuc = YANLIS;
        else if ( (sonuc) && (sutun < MAX) && (veri >= '0') && (veri <= '9')) {
            matris[satir][sutun++] = veri-48;
       }/*end if */
    }/* end while */
}/*end SatirGirisi */


/**************/
void Kare_cevirme(char tamp[], int kare)
/**************/
{/* bir 3 X 3'lik kare, bir boyutlu dizisine çevirme  */
    int i,j, x,y,z;
    x = (kare % MIN)*MIN;
    y = (((kare+MIN) / MIN)*MIN)-MIN;
    z = 0;
    for (j = y; j < y+MIN; j++) {
        for (i = x; i < x+MIN; i++) {
            tamp[z++] = matris[j][i];
        }/* end for i */
    }/* end for j */
}/* end Kare_cevirme */

/********************/
/**** cozum ****/
/********************/

/**********/
void Sudokuyu_coz(void)
/**********/
{
    int satir, sutun, sayi, sayi_tamp;
    for (satir = 0; satir < MAX; satir++) {
        for (sutun = 0; sutun < MAX; sutun++) {
            if (matris[satir][sutun]) continue;
            for (sayi = 1; sayi <= MAX; sayi++) {
                if (! BosyerVarMi(sayi, satir, sutun)) continue;
                sayi_tamp = matris[satir][sutun];
                matris[satir][sutun] = sayi;
                Sudokuyu_coz();
                if (BitmisMatris()) return;
                matris[satir][sutun] = sayi_tamp;
            }/* end for sayi */
            return;
        }/* end for sutun */
    }/* end for satır */
    return;
}/* end Sudokuyu_coz */

/******************/
int BosyerVarMi(int sayi, int satir, int sutun)
/******************/
{
    char tamp[MAX];
    int i;
    /*satırda sayi varsa YANLIS geri gönderilir*/
    for (i = 0; i < MAX; i++) if (matris[satir][i] == sayi) return(YANLIS);
    /*sutunda sayi sayi varsa YANLIS geri gönderilir */
    for (i = 0; i < MAX; i++) if (matris[i][sutun] == sayi) return(YANLIS);
    /* küçük karede sayi varsa YANLIS geri gönderilir */
    kareleri_cevirme(tamp, satir, sutun);
    for (i = 0; i < MAX; i++) if (tamp[i] == sayi) return (YANLIS);
    return(DOGRU);
}/* end BosyerVarMi */

/**********************/
void kareleri_cevirme(char tamp[], int satir, int sutun)
/**********************/
{
    int i, j, k;
    while ((satir % MIN) != 0) satir--;
    while ((sutun % MIN) != 0) sutun--;
    k = 0;
    for (j = satir; j < satir+MIN; j++) {
        for (i = sutun; i < sutun+MIN; i++) {
            tamp[++k] = matris[j][i];
        }/* end for i */
    }/* end for j */
}/* kareleri_cevirme */

/****************/
/**** DİĞERLERİ ****/
/****************/

/*****************/
void Matrisi_yaz(void)
/*****************/
{/* butün sudoku matrisi yazar */
    int satir, sutun;
    for (satir = 0; satir < MAX; satir++) {
        for (sutun = 0; sutun < MAX; sutun++) {
           printf(" %1d ", matris[satir][sutun]);
            if ( ((sutun % MIN) == MIN-1) && (sutun < MAX-1) ) {
                printf(" | ");
            }
        }/* end for sutun */
        printf("\n");
        if ( ((satir % MIN) == MIN-1) && (satir < MAX-1) ) {
            yildizlari_yaz(33);
        }
    }/* end for satır */
    printf("\n");
}/* end Matrisi_yaz */

/**************/
int BitmisMatris(void)
/**************/
/* matris bitmiş olup olmadığını kontrol eder.
matmiş ise DOGRU geri gönderir, aksi halde YANLIŞ gönderilir. */
{
    int satir, sutun;
    for (satir = MAX-1; satir >= 0; satir--) {
        for (sutun = MAX-1; sutun >= 0; sutun--) {
            if (matris[satir][sutun] == 0 ) {
                return YANLIS;
            }
        }/* end for sutun */
    }/* end for satir */
    return DOGRU;
}/* end BitmisMatris */

