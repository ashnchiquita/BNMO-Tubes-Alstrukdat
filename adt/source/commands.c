#include "../commands.h"
#include <stdio.h>
#include "../makanan.h"

void handleFoodCommand(ListMakanan l){
    while(!isFound(l, wordToInt(currentWord) - 1) && wordToInt(currentWord) != 0){
        printf("Nomor makanan tidak terdapat, silakan masukan input lagi\n");
        printCommand(l, strToWord("Buy"));
        printf("Enter command: \n");
    }
}

void notifikasiPembelian(Makanan m){
    printf("Berhasil memesan ");
    printWord(nama(m));
    printf(". ");
    printWord(nama(m));
    printf(" akan diantar dalam ");
    PrintKalimatDurasi(delivery(m));
    printf("\n");
}

void notifikasiGoreng(Makanan m){
    printWord(nama(m));
    printf(" selesai dibuat dan sudah dimasukkan ke inventory");
}

void notifikasiGagal(ListMakanan m){
    for(int i = 0; i < panjangListMakanan(m);i++){
        printf("%d.", i+1);
        printWord(nama(ELMT(m,i)));
        printf("\n");
    }
}