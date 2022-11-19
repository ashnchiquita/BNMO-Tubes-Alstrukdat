#ifndef CONFIG_H
#define CONFIG_H

#include "wordmachine.h"
#include "charmachine.h"
#include "time.h"
#include <stdio.h>
#include "makanan.h"
#include "matrix.h"

ListMakanan *configMakananP();
/* Membaca file makanan dalam file .txt, mengembalikan list makanan*/

Matrix configPeta(POINT *lokasiPemain);
/* Membaca file peta dalam file .txt, mengembalikan matrix peta */

#endif