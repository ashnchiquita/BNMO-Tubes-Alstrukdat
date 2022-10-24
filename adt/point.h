/* File: point.h */
/* Tanggal: 3 September 2022 */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#ifndef POINT_H
#define POINT_H

#include "boolean.h"

typedef struct { 
	int X; /* absis   */
	int Y; /* ordinat */
} POINT;

/*Define Maks X dan Maks Y (batas kanan dan atas peta)*/
// Nanti diubah kalau sudah ada adt peta 

#define Max_X 10
#define Max_Y 10

/*Define Min X dan Min Y*/
#define Min_X 0 
#define Min_Y 0

/* *** Notasi Akses: Selektor POINT *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y
        
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
void CreatePoint (POINT * P, int X, int Y);
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P); 
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
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

boolean isValid(int x, int y);

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