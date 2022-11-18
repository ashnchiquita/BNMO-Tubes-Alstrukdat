#include "../commands.h"
#include <stdio.h>
#include "../makanan.h"

void handleFoodCommand(ListMakanan l){
    while(!isFound(l, wordToInt(currentWord) - 1) && wordToInt(currentWord) != 0){
        printf("Nomor makanan tidak terdapat, silakan masukan input lagi\n");
        printCommand(l, strToWord("Buy"));
        printf("Enter command: \n");
        STARTWORD();
    }
}

void notifikasiPembelian(Makanan m){
    printf("Berhasil memesan ");
    printWord(nama(m));
    printf(". ");
    printWord(nama(m));
    printf(" akan diantar dalam ");
    PrintKalimatDurasi(actionTime(m));
    printf("\n");
}

void notifikasiGoreng(Makanan m){
    printWord(nama(m));
    printf(" selesai dibuat dan sudah dimasukkan ke inventory\n");
}

void notifikasiGagal(ListMakanan m){
    for(int i = 0; i < panjangListMakanan(m);i++){
        printf("%d.", i+1);
        printWord(nama(ELMT(m,i)));
        printf("\n");
    }
}
void handleFoodAction(ListTree treeResep, PrioQueue * Inventory,boolean *action, Makanan temp){
    Tree TempRecipe = *searchRecipeById(&treeResep,id(temp)); 

    /*ListMakanan completed adalah bahan - bahan makanan yang dibutuhkan dalam resep dan dimiliki inventory*/
    ListMakanan completed = getMakanan(TempRecipe,* Inventory);

    /*ListMakanan missed adalah bahan - bahan makanan yang dibutuhkan dalam resep, tpi tidak dimiliki inventory*/
    ListMakanan missed = getMakananNa(TempRecipe,* Inventory);

    /*Jika panjang list missed adalah 0, berarti semua makanan dimiliki, dan aksi menggoreng dapat dilakukan*/
    if(panjangListMakanan(missed) == 0){
        *action = true;
    }else{
        /*Jika panjang list makanan tidak sama dengan 0, berarti akan ada minimal satu item yang tidak dimiliki inventory*/
        printf("\nGagal membuat ");
        printWord(nama(temp));

        /*Menampilkan list makanan yang diperlukan, tapi tidak dimiliki */
        printf(" karena kamu tidak memiliki bahan berikut : \n");
        notifikasiGagal(missed);
    }
}

void addingFood(Makanan temp, PrioQueue *Inventory, ListTree treeResep,WordList *act, stateNotif *sn){
    Tree TempRecipe = *searchRecipeById(&treeResep,id(temp)); 
    /*ListMakanan completed adalah bahan - bahan makanan yang dibutuhkan dalam resep dan dimiliki inventory*/
    ListMakanan completed = getMakanan(TempRecipe,* Inventory);
    notifikasiGoreng(temp);
    for(int i = 0; i < panjangListMakanan(completed);i++){
        Makanan temp2;
        address food = indexOfName(* Inventory,nama(ELMT(completed,i)));
        deleteAtAdr(Inventory,food,&temp2);
        appendWL(nama(temp2), act);
    }
    setCommandArgs(sn, * act);
    Enqueue(Inventory,temp);
};
