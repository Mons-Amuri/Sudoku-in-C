#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

int main(int argc, char *argv[]);
/**** BILGI GIRISI VE KONTROL ETME ****/
int MatrisGirisi(void);
int SatirGirisi(int satir);
int MatrisGirisi_kontrolEt(void);
int Satirlari_kontrolEt(void);
int SatirGirisi_kontrolEt(int satir);
int Sutunlari_kontrolEt(void);
int SutunGirisi_kontrolEt(int sutun);
int Kareleri_kontrolEt(void);
int KareGirisi_kontrolEt(int kare);
void Kare_cevirme(char tamp[], int kare);
/**** ÇÖZÜM ****/
void Sudokuyu_coz(void);
int BosyerVarMi(int sayi, int satir, int sutun);
void kareleri_cevirme(char tamp[], int satir, int sutun);
/**** DIGERLERI ****/
void Matrisi_yaz(void);
void yildizlari_yaz(int sayi);
int BitmisMatris(void);


#endif // MAIN_H_INCLUDED
