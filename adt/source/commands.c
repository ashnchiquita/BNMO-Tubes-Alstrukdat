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