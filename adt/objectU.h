#ifndef BNMO_TUBES_ALSTRUKDAT_UNIONU_H
#define BNMO_TUBES_ALSTRUKDAT_UNIONU_H

#include "./Makanan/makanan.h"

typedef union objectU {
    int intV;
    Makanan makananV;
} Object;

#endif //BNMO_TUBES_ALSTRUKDAT_UNIONU_H
