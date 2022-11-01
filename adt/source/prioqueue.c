#include "../prioqueue.h"
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
void MakeEmptyQ (PrioQueue * Q, int Max, boolean sortDeliv) {
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dengan MaxEl = 0 */
/* Jika sortDeliv true, maka Q adalah delivery queue, jika false maka Q adalah inventory queue */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    /* KAMUS LOKAL */
    
    /* ALGORITMA */
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    SortDeliv(*Q) = sortDeliv;
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
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan: */
/* 1. Waktu delivery, jika Q adalah delivery queue */
/* 2. Waktu kealuarsa, jika Q adalah inventory queue  */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas, Tail maju */
    /* KAMUS LOKAL */
    address i, idxSisip;
    boolean found, compareTime;

    /* ALGORITMA */
    if (IsEmpty(*Q)) {
        Head(*Q) = 0;
        Tail(*Q) = 0;
        setElmt(Q, 0, X);
    } else {
        found = false;
        for (i =  Head(*Q); i <= Tail(*Q) && !found; i++) {
            if (SortDeliv(*Q)) {
                compareTime = TGT(delivery(Elmt(*Q, i)), delivery(X));
            } else {
                compareTime = TGT(expired(Elmt(*Q, i)), expired(X));
            }
            
            if (compareTime) {
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
    /* KAMUS LOKAL */
    address i;

    /* ALGORITMA */
    if (!IsEmpty(Q)) {
        for (i =  Head(Q); i <= Tail(Q); i++) {
            printf("%d. ", i + 1);
            printWord(nama(Elmt(Q, i)));
            printf(" (");
            if (SortDeliv(Q)) {
                PrintKalimatDurasi(delivery(Elmt(Q, i)));
            } else {
                PrintKalimatDurasi(expired(Elmt(Q, i)));
            }
            printf(")\n");
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
    MakeEmptyQ(Q2, MaxEl(Q1), SortDeliv(Q1));
    
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
    boolean prevSort;

    /* ALGORITMA */
    prevMaxEl = MaxEl(*Q);
    prevSort = SortDeliv(*Q);
    copyPrioQueue(*Q, &temp);
    DeAlokasi(Q);
    MakeEmptyQ(Q, prevMaxEl + num, prevSort);
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
    boolean prevSort;

    /* ALGORITMA */
    prevMaxEl = MaxEl(*Q);
    prevSort = SortDeliv(*Q);
    copyPrioQueue(*Q, &temp);
    DeAlokasi(Q);
    MakeEmptyQ(Q, prevMaxEl - num, prevSort);
    copyPrioQueue(temp, Q);
    DeAlokasi(&temp);
}


/* MEKANISME WAKTU */
void update1Min(PrioQueue *Q) {
/* I.S. Q terdefinisi, Q mungkin kosong */
/* F.S. Jika Q adalah delivery queue, waktu delivery tiap Makanan di Q berkurang 1 menit. Jika ada yang awalnya waktu deliverynya < N menit, waktu delivery akan menjadi nol */
/* Jika Q adalah inventory queue, waktu kedaluarsa tiap Makanan di Q berkurang 1 menit. Jika ada yang awalnya waktu kedaluarsanya < N menit, waktu kedaluarsa akan menjadi nol (expired) */
    /* KAMUS LOKAL */
    address i;
    TIME zeroTime;

    /* ALGORITMA */
    if(!IsEmpty(*Q)) {
        for (i = Head(*Q); i <= Tail(*Q); i++) {
            if (SortDeliv(*Q)) {
                if (!isZeroTIME(delivery(Elmt(*Q, i)))) {
                    PrevMenit(&delivery(Elmt(*Q, i)));
                } else {
                    CreateTime (&zeroTime, 0, 0, 0);
                    delivery(Elmt(*Q, i)) = zeroTime;
                }
            } else {
                if (!isZeroTIME(expired(Elmt(*Q, i)))) {
                    PrevMenit(&expired(Elmt(*Q, i)));
                } else {
                    CreateTime (&zeroTime, 0, 0, 0);
                    expired(Elmt(*Q, i)) = zeroTime;
            }
            }
        }
    }
}

void cleanKedaluarsa (PrioQueue *inventQ) {
/* I.S. inventQ terdefinisi, inventQ mungkin kosong, inventQ adalah inventory */
/* F.S. Elemen yang expired (waktu kedaluarsanya nol) terhapus dari inventQ */
    /* KAMUS LOKAL */
    infotype temp;
    int count, prevLength;

    /* ALGORITMA */
    count = 0;
    prevLength = CountElmt(*inventQ);
    if (!IsEmpty(*inventQ)) {
        while (count < prevLength && isZeroTIME(expired(InfoHead(*inventQ)))) {
            Dequeue(inventQ, &temp);
            count++;
            /* add makanan temp ke notif, tipe notif: makanan kedaluarsa */
        }
    }
}

void finishDelivery (PrioQueue * delivQ, PrioQueue * inventQ) {
/* I.S. delivQ terdefinisi, delivQ mungkin kosong, delivQ adalah delivery queue, inventQ adalah inventory queue */
/* F.S. Elemen delivQ yang waktu deliverynya 0 dimasukkan ke inventQ */
    /* KAMUS LOKAL */
    infotype temp;
    int count, prevLength;

    /* ALGORITMA */
    count = 0;
    prevLength = CountElmt(*delivQ);
    if (!IsEmpty(*delivQ)) {
        while (count < prevLength && isZeroTIME(delivery(InfoHead(*delivQ)))) {
            Dequeue(delivQ, &temp);
            Enqueue(inventQ, temp);
            count++;
            /* add makanan temp ke notif, tipe notif: makanan sampai */
        }
    }
}

void updateAllQueue(PrioQueue * delivQ, PrioQueue * inventQ, int nMenit) {
/* I.S. delivQ, inventQ, nMenit terdefinisi */
/* F.S. delivery queue dan inventory queue terupdate nMenit menit */
    /* KAMUS LOKAL */
    int i;

    /* ALGORITMA */
    for (i = 1; i <= nMenit; i++) {
        update1Min(delivQ);
        update1Min(inventQ);
        cleanKedaluarsa(inventQ);
        finishDelivery(delivQ, inventQ);
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
        if (wordEqual(nama(Elmt(Q, i)), name)) {
            found = true;
        } else {
            i++;
        }
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
            if (wordEqual(nama(Elmt(Q, i)), name)) {
                count++;
            }
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
