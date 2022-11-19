/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackt_H
#define stackt_H

#include "../boolean.h"
#include "../Makanan/makanan.h"
#include "../Prioqueue/prioqueue.h"
#include "../Time/time.h"
#include "../Point/point.h"
#include "../Notifikasi/notif.h"
#include "../Kulkas/kulkas.h"

#define Nil -1
#define MaxStack 100
/* Nil adalah stack dengan elemen kosong . */

typedef struct states
{
    TIME waktuMain;
    POINT posisiPemain; 
    PrioQueue delivery;
    PrioQueue inventory;
    listKulkas lk;
    treeArr t;
    stateNotif sn;
}states;

typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  states T[MaxStack]; /* tabel penyimpan elemen */
  address TOP;  /* alamat TOP: elemen puncak */
} Stack;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define TopStack(S) (S).TOP
#define InfoTopStack(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStack(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStack(Stack * S, states X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack(Stack * S, states* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void UNDO(Stack *states, Stack *redo, TIME *waktuMain, POINT *lokasi, PrioQueue *delivery, PrioQueue *inventory,listKulkas * lk, treeArr *t, stateNotif * sn);
/* Mengembalikan state ke sebelumnya */
/* I.S. *waktuMain, *lokasi, *delivery, dan *inventory terdefinisi */
/* F.S. Meng-assign nilai state sebelumnya ke dalam masing - masing variabel */

void REDO(Stack *states, Stack *redo, TIME *waktuMain, POINT *lokasi, PrioQueue *delivery, PrioQueue *inventory, listKulkas * lk, treeArr *t, stateNotif * sn);
/* Mengembalikan state ke keadaan sebelum procedure UNDO dipanggil */
/* I.S. *waktuMain, *lokasi, *delivery, dan *inventory terdefinisi */
/* F.S. Meng-assign nilai state sebelum UNDO ke dalam masing - masing variabel */

void printState(states temp);
/*Menampilkan states ke layar */
/* I.S. States temp terdefinisi */
/* F.S. Menampilkan waktu permainan, lokasi pemain, list delivery, dan list inventory ke layar */

void printStack(Stack S);
/* Menampilkan Stack ke layar */
/* I.S. Stack S terdefinisi dan mungkin kosong */
/* F.S. Menampilkan semua states dalam S ke layar */

int stackLength (Stack S);
/* Mengembalikan banyaknya states dalam sebuah Stack */

#endif