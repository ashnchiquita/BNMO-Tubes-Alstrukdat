#include "../simulator.h"
#include <stdio.h>

int main(){
    Simulator S;
    Word nama = {"Nathania Calista",16};
    createSimulator(&S,nama);
    printWord(namaPemain(S));
    TulisPOINT(lokasiPemain(S));
    
}