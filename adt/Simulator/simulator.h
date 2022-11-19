#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "../Wordmachine/wordmachine.h"
#include "../Charmachine/charmachine.h"
#include "../Prioqueue/prioqueue.h"
#include "../Point/point.h"

typedef struct 
{
    POINT lokasi;
    Word namaPemain;
    /*Tunggu bagian inventory kelar*/
    PrioQueue inventory;
}Simulator;

#define namaPemain(S) (S).namaPemain
#define lokasiPemain(S) (S).lokasi
#define inventory(S) (S).inventory
 
void createSimulator(Simulator *S, POINT p, Word nama, PrioQueue inventory);
/* I.S : S,p, dan nama terdefinisi */
/* F.S. : Meng-assign nilai POINT simulator menjadi p dan nilai Nama simulator menjadi nama */
#endif