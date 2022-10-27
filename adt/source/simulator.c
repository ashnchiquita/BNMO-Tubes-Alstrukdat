#include "../simulator.h"
#include <stdio.h>

void createSimulator(Simulator *S, Word namaPemain){
    POINT startPoint = {0,0};
    namaPemain(*S) = namaPemain;
    lokasiPemain(*S) = startPoint;
}
