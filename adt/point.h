/* File: point.h */
/* Tanggal: 3 September 2022 */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#ifndef POINT_H
#define POINT_H

#include "boolean.h"

typedef struct { 
	int X; /* absis   */
	int Y; /* ordinat */
   int maxKanan;
   int maxBawah;
} POINT;

/*Define Maks X dan Maks Y (batas kanan dan atas peta)*/
// Nanti diubah kalau sudah ada adt peta 

/*Define Min X dan Min Y*/
#define Min_X 0 
#define Min_Y 0

/* *** Notasi Akses: Selektor POINT *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y
#define MAXB(P) (P).maxBawah
#define MAXK(P) (P).maxKanan

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
void CreatePoint (POINT * P, int maxKanan, int maxKiri);
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void TulisPOINT (POINT P);
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P);
/* Menghasilkan true jika P adalah titik origin */

boolean isValid(POINT P,int x, int y);

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
void NextX (POINT *P);
/* Mengirim salinan P dengan absis ditambah satu */              
void NextY (POINT *P);
/* Mengirim salinan P dengan ordinat ditambah satu */

void PrevX(POINT *P);
// Mengirim salinan P dengan absis dikurangi 1

void PrevY (POINT *P);
// Mengirim salinan P dengan ordinat dikurangi 1 


#endif