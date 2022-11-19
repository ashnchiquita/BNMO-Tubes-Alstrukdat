/* File : prioqueue.h */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Elemen queue terurut membesar berdasarkan elemen time */

#ifndef PRIOQUEUE_H
#define PRIOQUEUE_H

#include "../boolean.h"
#include "../Makanan/makanan.h"
#include "../Time/time.h"
#include "../Wordmachine/wordmachine.h"
#include "../Notifikasi/notif.h"

/* Konstanta untuk mendefinisikan address tak terdefinisi */
#define Nil -1

/* Definisi Elemen dan Address */
/* Elemen */
typedef Makanan infotype;
/* Indeks Tabel */
typedef int address;
/* Struct PrioQueue */
typedef struct {
    boolean SortDeliv; /* true: sort priority berdasarkan waktu delivery (delivery queue), false: sort priority berdasarkan waktu kedaluarsa (inventory queue) */
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
#define SortDeliv(Q) (Q).SortDeliv
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
void MakeEmptyQ (PrioQueue * Q, int Max, boolean sortDeliv);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dengan MaxEl = 0 */
/* Jika sortDeliv true, maka Q adalah delivery queue, jika false maka Q adalah inventory queue */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */


/* *** Destruktor *** */
void DeAlokasi(PrioQueue * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */


/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueue * Q, infotype X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan: */
/* 1. Waktu delivery, jika Q adalah delivery queue */
/* 2. Waktu kealuarsa, jika Q adalah inventory queue  */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas, Tail maju */

void Dequeue (PrioQueue * Q, infotype * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., Tail mundur */


/* Operasi Tambahan */
void PrintPrioQueue (PrioQueue Q);
/* Mencetak isi PrioQueue Q ke layar */
/* Jika Q adalah delivery queue, waktu yang diprint adalah waktu delivery */
/* Jika Q adalah inventory queue, waktu yang diprint adalah waktu kedaluarsa */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
    < address + 1 >. < nama makanan > (< waktu delivery/kedaluarsa >)
    ...
    < CountElmt(Q) >. < nama makanan > (< waktu delivery/kedaluarsa >)
    Di akhir terdapat "\n"
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
/* F.S. Jika Q adalah delivery queue, waktu delivery tiap Makanan di Q berkurang 1 menit. Jika ada yang awalnya waktu deliverynya < N menit, waktu delivery akan menjadi nol */
/* Jika Q adalah inventory queue, waktu kedaluarsa tiap Makanan di Q berkurang 1 menit. Jika ada yang awalnya waktu kedaluarsanya < N menit, waktu kedaluarsa akan menjadi nol (expired) */

void cleanKedaluarsa (PrioQueue *inventQ, stateNotif * sn);
/* I.S. inventQ terdefinisi, inventQ mungkin kosong, inventQ adalah inventory */
/* F.S. Elemen yang expired (waktu kedaluarsanya nol) terhapus dari inventQ */

void finishDelivery (PrioQueue * delivQ, PrioQueue * inventQ, stateNotif * sn);
/* I.S. delivQ terdefinisi, delivQ mungkin kosong, delivQ adalah delivery queue, inventQ adalah inventory queue */
/* F.S. Elemen delivQ yang waktu deliverynya 0 dimasukkan ke inventQ */

void updateAllQueue(PrioQueue * delivQ, PrioQueue * inventQ, int nMenit, stateNotif * sn);
/* I.S. delivQ, inventQ, nMenit terdefinisi */
/* F.S. delivery queue dan inventory queue terupdate nMenit menit */


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
void deleteAtAdr(PrioQueue *Q, address idx, infotype *X);
/* I.S. Q terdefinisi, Q tidak kosong, idx adalah address yang valid untuk PrioQueue Q */
/* F.S. Elemen di address i terhapus */


#endif