#ifndef CONFIG_H
#define CONFIG_H

#include "../Wordmachine/wordmachine.h"
#include "../Charmachine/charmachine.h"
#include "../Time/time.h"
#include <stdio.h>
#include "../Makanan/makanan.h"
#include "../Matrix/matrix.h"

ListMakanan *configMakananP();
/* Membaca file makanan dalam file .txt, mengembalikan list makanan*/

Matrix configPeta(POINT *lokasiPemain);
/* Membaca file peta dalam file .txt, mengembalikan matrix peta */

#endif