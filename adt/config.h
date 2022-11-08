#ifndef CONFIG_H
#define CONFIG_H

#include "wordmachine.h"
#include "charmachine.h"
#include "time.h"
#include <stdio.h>
#include "makanan.h"
#include "matrix.h"

ListMakanan configMakanan();
ListMakanan *configMakananP();
Matrix configPeta(POINT *lokasiPemain);


#endif