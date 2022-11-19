#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "wordmachine.h"
#include "charmachine.h"
#include "point.h"

typedef struct 
{
    POINT lokasi;
    Word namaPemain;
    /*Tunggu bagian inventory kelar*/
    // ListDin inventory;
}Simulator;

#define namaPemain(S) (S).namaPemain
#define lokasiPemain(S) (S).lokasi

void createSimulator(Simulator *S, POINT p, Word nama);
/* I.S : S,p, dan nama terdefinisi */
/* F.S. : Meng-assign nilai POINT simulator menjadi p dan nilai Nama simulator menjadi nama */
#endif