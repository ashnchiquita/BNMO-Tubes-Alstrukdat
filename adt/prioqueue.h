/* File : prioqueue.h */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen time */

#ifndef PRIOQUEUE_H
#define PRIOQUEUE_H

#include "boolean.h"
#include "makanan.h"
#include "time.h"

/* Konstanta untuk mendefinisikan address tak terdefinisi */
#define Nil -1

/* Definisi Elemen dan Address */
/* Elemen */
typedef infotype infotype;
/* Indeks Tabel */
typedef int address;
/* Struct PrioQueue */
typedef struct {
    infotype * T;  /* Tabel penyimpan elemen */
    address HEAD;  /* Alamat penghapusan (head) */
    address TAIL;  /* Alamat penambahan (tail) */
    int MaxEl;     /* Max elemen queue */
} PrioQueue;
/* Definisi PrioQueue kosong: HEAD = Nil; TAIL = Nil. */

/* ********* AKSES (Selektor) ********* */
/* Jika Q adalah PrioQueue, maka akses elemen : */
#define Head(Q)     (Q).HEAD
#define Tail(Q)     (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q)    (Q).MaxEl
#define Elmt(Q,i)   (Q).T[(i)]


/* ********* Prototype ********* */
boolean IsEmpty (PrioQueue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */

boolean IsFull (PrioQueue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */

int CountElmt (PrioQueue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty (PrioQueue * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dengan MaxEl = 0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */


/* *** Destruktor *** */
void DeAlokasi(PrioQueue * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */


/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueue * Q, infotype X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan waktu kedaluarsa */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas, Tail maju */

void Dequeue (PrioQueue * Q, infotype * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., Tail mundur */


/* Operasi Tambahan */
void PrintPrioQueue (PrioQueue Q);
    /* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
    < address + 1 >. < nama makanan > (< waktu kedaluarsa >)
    ...
    < CountElmt(Q) >. < nama makanan > (< waktu kedaluarsa >)
    Di akhir terdapat '\n'
*/

void copyPrioQueue(PrioQueue Q1, PrioQueue * Q2);
/* I.S. Q1 terdefinisi, Q2 sembarang */
/* F.S. Q2 berisi salinan elemen Q1 */


/* ********* MENGUBAH MAXEL ********* */
void expandPrioQueue(PrioQueue *Q, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. PrioQueue sudah terdefinisi */
/* F.S. MaxEl bertambah sebanyak num */

void shrinkPrioQueue(PrioQueue *Q, int num);
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */


/* MEKANISME WAKTU */
void update1Min(PrioQueue *Q);
/* I.S. Q terdefinisi, Q mungkin kosong */
/* F.S. Waktu kedaluarsa tiap Makanan di Q berkurang 1 menit. Jika ada yang awalnya waktu kedaluarsanya < 1 menit, waktu kedaluarsa akan menjadi nol (expired) */

void updateNMin(PrioQueue *Q, int N);
/* I.S. Q terdefinisi, Q mungkin kosong */
/* F.S. Waktu kedaluarsa tiap Makanan di Q berkurang 1 menit. Jika ada yang awalnya waktu kedaluarsanya < N menit, waktu kedaluarsa akan menjadi nol (expired) */

void cleanKedaluarsa (PrioQueue *Q);
/* I.S. Q terdefinisi, Q mungkin kosong */
/* F.S. Elemen yang expired (waktu kedaluarsanya nol) terhapus dari Q */


/* LAIN-LAIN: PERLAKUAN SEPERTI ARRAY */
/* Prototype */
boolean isAdrValid(PrioQueue Q, address i);
/* Mengirimkan true jika i adalah address yang valid untuk Q */
/* yaitu antara Head(Q)..Tail(Q) */

address indexOfName(PrioQueue Q, Word name);
/* I.S. Q dan nama terdefinisi */
/* F.S. Mengembalikan address pertama ditemukannya Makanan dengan nama name, jika tidak ada mengembalikan Nil */

int countName (PrioQueue Q, Word name);
/* I.S. Q dan nama terdefinisi, Q mungkin kosong */
/* F.S. Mengembalikan jumlah kemunculan Makanan bernama name dalam Q */


/* Setter */
void setElmt(PrioQueue * Q, address idx, infotype X);
/* I.S. Q terdefinisi, idx adalah address yang valid untuk PrioQueue Q */
/* F.S. Elmt(*Q, idx) = X */
/* Penggunaan prosedur ini harus mempertahankan keterurutan PrioQueue */


/* Delete */
void deleteAt(PrioQueue *Q, address idx, infotype *X);
/* I.S. Q terdefinisi, Q tidak kosong, idx adalah address yang valid untuk PrioQueue Q */
/* F.S. Elemen di address i terhapus */

void deleteElmt(PrioQueue *Q, Word name, infotype *X);
/* I.S. Q terdefinisi, Q tidak kosong */
/* F.S. Jika X ada di Q, maka makanan pertama yang bernama name dihapus dari Q, jika tidak, tidak melakukan apa-apa */

#endif