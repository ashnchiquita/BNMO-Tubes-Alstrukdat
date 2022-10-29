#include "../commands.h"
#include <stdio.h>
#include "../iohandling.h"

void handleFoodCommand(ListMakanan l, Word aksi){
    while(!isFound(l, wordToInt(aksi) - 1) && wordToInt(aksi) != 0){
        printf("Nomor makanan tidak terdapat, silakan masukan input lagi\n");
        printCommand(l, strToWord("Buy"));
        printf("Enter command: \n");
        aksi = (takeInput()).T[0];
    }
}