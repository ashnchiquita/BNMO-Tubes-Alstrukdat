#include "simulator.h"
#include <stdio.h>

int main(){
    Simulator S;
    POINT p;
    PrioQueue Inventory;
    Word nama = {"Nathania Calista",16};
    CreatePoint(&p,2,5);
    createSimulator(&S,p,nama,Inventory);
    printWord(namaPemain(S));
    TulisPOINT(lokasiPemain(S));
}