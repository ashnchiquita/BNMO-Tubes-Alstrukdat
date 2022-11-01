#include "../stack.h"
#include <stdio.h>
#include "../matrix.h"

void CreateEmptyStack(Stack *S){
    TopStack(*S) = Nil;
};
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S){
    return(TopStack(S) == Nil);
};
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStack(Stack S){
    return(TopStack(S) == MaxStack-1);
};
/* Mengirim true jika tabel penampung nilai elemen stack penuh */


/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStack(Stack * S, states X){
    if(IsEmptyStack(*S)){
        TopStack(*S) = 0;
        InfoTopStack(*S) = X;
    } else {
        TopStack(*S)++;
        InfoTopStack(*S) = X;
    }
};
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack(Stack * S, states* X){
    *X = InfoTopStack(*S);
    if(TopStack(*S) == 0){
        TopStack(*S) = Nil;
    }else{
        TopStack(*S) -= 1;
    }
};
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
void UNDO(Stack *stackCommand, Stack redo, TIME *waktuMain, POINT *lokasi, PrioQueue *delivery, PrioQueue *inventory){
    states top;
    states temp;
    PopStack(stackCommand,&top);
    PrintPrioQueue(top.delivery);
    PushStack(&redo,top); 
    if(!IsEmptyStack(*stackCommand)){
        PopStack(stackCommand,&top);
        PrintPrioQueue(top.delivery);
        *waktuMain = top.waktuMain;
        *lokasi = top.posisiPemain;
        *delivery = top.delivery;
        *inventory = top.inventory;
    }else{
        printf("Stack kosong");
    }
    
    
};
