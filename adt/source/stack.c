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
void UNDO(Stack *stackCommand, Stack *redo, TIME *waktuMain, POINT *lokasi, PrioQueue *delivery, PrioQueue *inventory,  stateNotif * sn){
    states top;
    states temp;
    if(stackLength(*stackCommand) > 1){
        PopStack(stackCommand,&top);
        PushStack(redo,top); 
        *waktuMain = InfoTopStack(*stackCommand).waktuMain;
        *lokasi = InfoTopStack(*stackCommand).posisiPemain;
        *delivery = InfoTopStack(*stackCommand).delivery;
        *inventory = InfoTopStack(*stackCommand).inventory;
        *sn = InfoTopStack(*stackCommand).sn;
    }else{
        printf("BNMO sudah berada pada keadaan semula, tidak bisa UNDO!\n");
    }
    
};
void REDO(Stack *stackCommand, Stack *redo, TIME *waktuMain, POINT *lokasi, PrioQueue *delivery, PrioQueue *inventory, stateNotif * sn){
    states top; 
    states temp;
    
    if(!IsEmptyStack(*redo)){
        PopStack(redo,&top);
        PushStack(stackCommand,top);
        *waktuMain = top.waktuMain;
        *lokasi = top.posisiPemain;
        *delivery = top.delivery;
        *inventory = top.inventory;
        *sn = top.sn;
    }else{
        printf("Tidak ada command yang bisa di-redo!\n");
    }
}
void printState(states temp){
    printf("====Waktu game ===\n");
    TulisTIME(temp.waktuMain);
    printf("\n====Delivery====\n");
    PrintPrioQueue(temp.delivery);
    printf("=====inventory========\n");
    PrintPrioQueue(temp.inventory);
    printf("=====lokasi pemain====\n");
    TulisPOINT(temp.posisiPemain);
}

void printStack(Stack S){
    states temp;
    while(!IsEmptyStack(S)){
        printf("\n==============GANTI STATE============\n");
        PopStack(&S,&temp);
        printState(temp);
    }
}

int stackLength(Stack S){
    int count = 0; 
    states temp;
    while (!IsEmptyStack(S))
    {
        PopStack(&S,&temp);
        count++;
    }
    return count;
    
}
