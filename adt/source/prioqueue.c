#include "../boolean.h"
#include "../prioqueue.h"
#include "../makanan.h"
#include "../time.h"
#include <stdio.h>
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueue Q) {
/* Mengirim true jika Q kosong: lihat definisi di atas */
    /* KAMUS LOKAL */
    
    /* ALGORITMA */
    return (Head(Q) == Nil && Tail(Q) == Nil);
}

boolean IsFull (PrioQueue Q) {
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
    /* KAMUS LOKAL */
    
    /* ALGORITMA */
    return (Tail(Q) == MaxEl(Q) - 1);
}

int CountElmt (PrioQueue Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    /* KAMUS LOKAL */
    int len;

    /* ALGORITMA */
    len = 0;

    if (!IsEmpty(Q)) {
        len = Tail(Q) - Head(Q) + 1;
    }

    return len;
}

/* *** Kreator *** */
void MakeEmpty (PrioQueue * Q, int Max) {
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dengan MaxEl = 0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    /* KAMUS LOKAL */
    
    /* ALGORITMA */
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    (*Q).T = (infotype *) malloc(Max * sizeof(infotype));

    if ((*Q).T != NULL) {
        MaxEl(*Q) = Max;
    } else {
        MaxEl(*Q) = 0;
    }
}


/* *** Destruktor *** */
void DeAlokasi(PrioQueue * Q) {
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
    /* KAMUS */
    
    /* ALGORITMA */
    free((*Q).T);
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    MaxEl(*Q) = 0;
}


/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueue * Q, infotype X) {
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan waktu kedaluarsa */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas, Tail maju */
    /* KAMUS LOKAL */
    address i, idxSisip;
    boolean found;

    /* ALGORITMA */
    if (IsEmpty(*Q)) {
        Head(*Q) = 0;
        Tail(*Q) = 0;
        setElmt(Q, 0, X);
    } else {
        found = false;
        for (i =  Head(*Q); i <= Tail(*Q) && !found; i++) {
            if (TGT(expired(Elmt(*Q, i)), expired(X)) ) {
                idxSisip = i;
                found = true;
            }
        }

        if (!found) {
            idxSisip = Tail(*Q) + 1;
        }

        for (i = Tail(*Q) + 1; i >= idxSisip + 1; i--) {
            setElmt(Q, i, Elmt(*Q, i - 1));
        }

        Tail(*Q)++;
        setElmt(Q, idxSisip, X);
    }
}

void Dequeue (PrioQueue * Q, infotype * X) {
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., Tail mundur */
    /* KAMUS LOKAL */
    address i;

    /* ALGORITMA */
    id(*X) = id(InfoHead(*Q));
    nama(*X) = nama(InfoHead(*Q));
    expired(*X) = expired(InfoHead(*Q));
    delivery(*X) = delivery(InfoHead(*Q));
    aksi(*X) = aksi(InfoHead(*Q));

    if (CountElmt(*Q) == 1) {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        for (i = 1; i <= Tail(*Q); i++) {
            setElmt(Q, i - 1, Elmt(*Q, i));
        }

        Tail(*Q)--;
    }
}

/* Operasi Tambahan */
void PrintPrioQueue (PrioQueue Q) {
    /* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
    < address + 1 >. < nama makanan > (< waktu kedaluarsa >)
    ...
    < CountElmt(Q) >. < nama makanan > (< waktu kedaluarsa >)
    Di akhir terdapat "\n"
*/
    /* KAMUS LOKAL */
    address i;

    /* ALGORITMA */
    if (!IsEmpty(Q)) {
        for (i =  Head(Q); i <= Tail(Q); i++) {
            printf("%d. ", i + 1);
            // printWord(nama(Elmt(Q, i)));
            printf(" (");
            PrintKalimatDurasi(expired(Elmt(Q, i)));
            printf(" )\n");
        }
    } else {
        printf("\n");
    }
}

void copyPrioQueue(PrioQueue Q1, PrioQueue * Q2) {
/* I.S. Q1 terdefinisi, Q2 sembarang */
/* F.S. Q2 berisi salinan elemen Q1 */
    /* KAMUS LOKAL */
    address i;

    /* ALGORITMA */
    MakeEmpty(Q2, MaxEl(Q1));
    
    Head(*Q2) = Head(Q1);
    Tail(*Q2) = Tail(Q1);

    if(!IsEmpty(Q1)) {
        for(i = Head(*Q2); i <= Tail(*Q2); i++) {
            setElmt(Q2, i, Elmt(Q1, i));
        }
    }
}

/* ********* MENGUBAH MAXEL ********* */
void expandPrioQueue(PrioQueue *Q, int num) {
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. PrioQueue sudah terdefinisi */
/* F.S. MaxEl bertambah sebanyak num */
    /* KAMUS LOKAL */
    PrioQueue temp;
    int prevMaxEl;

    /* ALGORITMA */
    prevMaxEl = MaxEl(*Q);
    copyPrioQueue(*Q, &temp);
    DeAlokasi(Q);
    MakeEmpty(Q, prevMaxEl + num);
    copyPrioQueue(temp, Q);
    DeAlokasi(&temp);
}

void shrinkPrioQueue(PrioQueue *Q, int num) {
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
    /* KAMUS LOKAL */
    PrioQueue temp;
    int prevMaxEl;

    /* ALGORITMA */
    prevMaxEl = MaxEl(*Q);
    copyPrioQueue(*Q, &temp);
    DeAlokasi(Q);
    MakeEmpty(Q, prevMaxEl - num);
    copyPrioQueue(temp, Q);
    DeAlokasi(&temp);
}


/* MEKANISME WAKTU */
void update1Min(PrioQueue *Q) {
/* I.S. Q terdefinisi, Q mungkin kosong */
/* F.S. Waktu kedaluarsa tiap Makanan di Q berkurang 1 menit. Jika ada yang awalnya waktu kedaluarsanya < 1 menit, waktu kedaluarsa akan menjadi nol (expired) */
    /* KAMUS LOKAL */
    address i;
    TIME zeroTime;

    /* ALGORITMA */
    if(!IsEmpty(*Q)) {
        for (i = Head(*Q); i <= Tail(*Q); i++) {
            if (!isZeroTIME(expired(Elmt(*Q, i)))) {
                PrevMenit(&expired(Elmt(*Q, i)));
            } else {
                CreateTime (&zeroTime, 0, 0, 0);
                expired(Elmt(*Q, i)) = zeroTime;
            }
        }
    }
}

void updateNMin(PrioQueue *Q, int N) {
/* I.S. Q terdefinisi, Q mungkin kosong */
/* F.S. Waktu kedaluarsa tiap Makanan di Q berkurang 1 menit. Jika ada yang awalnya waktu kedaluarsanya < N menit, waktu kedaluarsa akan menjadi nol (expired) */
    /* KAMUS LOKAL */
    address i;
    TIME zeroTime;

    /* ALGORITMA */
        if(!IsEmpty(*Q)) {
        for (i = Head(*Q); i <= Tail(*Q); i++) {
            if (TGT(expired(Elmt(*Q, i)), MenitToTIME(N))) {
                PrevNMenit(&expired(Elmt(*Q, i)), N);
            } else {
                CreateTime (&zeroTime, 0, 0, 0);
                expired(Elmt(*Q, i)) = zeroTime;
            }
        }
    }
}

void cleanKedaluarsa (PrioQueue *Q) {
/* I.S. Q terdefinisi, Q mungkin kosong */
/* F.S. Elemen yang expired (waktu kedaluarsanya nol) terhapus dari Q */
    /* KAMUS LOKAL */
    infotype temp;

    /* ALGORITMA */
    if (!IsEmpty(*Q)) {
        while (isZeroTIME(expired(InfoHead(*Q)))) {
            Dequeue(Q, &temp);
        }
    }
}

/* LAIN-LAIN: PERLAKUAN SEPERTI ARRAY */
/* Prototype */
boolean isAdrValid(PrioQueue Q, address i) {
/* Mengirimkan true jika i adalah address yang valid untuk Q */
/* yaitu antara Head(Q)..Tail(Q) */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    return i >= Head(Q) && i <= Tail(Q);
}

address indexOfName(PrioQueue Q, Word name) {
/* I.S. Q dan nama terdefinisi */
/* F.S. Mengembalikan address pertama ditemukannya Makanan dengan nama name, jika tidak ada mengembalikan Nil */
    /* KAMUS LOKAL */
    address i;
    boolean found;

    /* ALGORITMA */
    i = 0;
    found = false; 
    while (i <= Tail(Q) && !found) {
        /* if (isWordEq(nama(Elmt(Q, i)), name)) {
            found = true;
        } else {
            i++;
        }*/
    }

    if (found) {
        return i;
    } else {
        return Nil;
    }
}

int countName (PrioQueue Q, Word name) {
/* I.S. Q dan nama terdefinisi, Q mungkin kosong */
/* F.S. Mengembalikan jumlah kemunculan Makanan bernama name dalam Q */
    /* KAMUS LOKAL */
    address i;
    int count;

    /* ALGORITMA */
    count = 0;

    if(!IsEmpty(Q)) {
        for (i = Head(Q); i <= Tail(Q); i++) {
            /* if (isWordEq(nama(Elmt(Q, i)), name)) {
                count++;
            }*/
        }
        
    }

    return count;
}

/* Setter */
void setElmt(PrioQueue * Q, address idx, infotype X) {
/* I.S. Q terdefinisi, idx adalah address yang valid untuk PrioQueue Q */
/* F.S. Elmt(*Q, idx) = X */
/* Penggunaan prosedur ini harus mempertahankan keterurutan PrioQueue */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    id(Elmt(*Q, idx)) = id(X);
    nama(Elmt(*Q, idx)) = nama(X);
    expired(Elmt(*Q, idx)) = expired(X);
    delivery(Elmt(*Q, idx)) = delivery(X);
    aksi(Elmt(*Q, idx)) = aksi(X);
}

/* Delete */
void deleteAtAdr(PrioQueue *Q, address idx, infotype *X) {
/* I.S. Q terdefinisi, Q tidak kosong, idx adalah address yang valid untuk PrioQueue Q */
/* F.S. Elemen di address i terhapus */
    /* KAMUS LOKAL */
    address i;

    /* ALGORITMA */
    if (idx == 0) {
        Dequeue(Q, X);
    } else {
        id(*X) = id(Elmt(*Q, idx));
        nama(*X) = nama(Elmt(*Q, idx));
        expired(*X) = expired(Elmt(*Q, idx));
        delivery(*X) = delivery(Elmt(*Q, idx));
        aksi(*X) = aksi(Elmt(*Q, idx));

        for (i = idx + 1; i <= Tail(*Q); i++) {
            setElmt(Q, i - 1, Elmt(*Q, i));
        }

        Tail(*Q)--;
    }
}

void deleteElmt(PrioQueue *Q, Word name, infotype *X) {
/* I.S. Q terdefinisi, Q tidak kosong */
/* F.S. Jika X ada di Q, maka makanan pertama yang bernama name dihapus dari Q, jika tidak, tidak melakukan apa-apa */
    /* KAMUS LOKAL */
    address i;

    /* ALGORITMA */
    i = indexOfName(*Q, name);
    if (i != Nil) {
        deleteAtAdr(Q, i, X);
    }
}