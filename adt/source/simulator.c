#include "../simulator.h"
#include <stdio.h>

void createSimulator(Simulator *S, POINT p,Word namaPemain){
    CreatePoint(&p,10,10);
    namaPemain(*S) = namaPemain;
    lokasiPemain(*S) = p;
}
