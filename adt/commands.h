#ifndef COMMANDS_H
#define COMMANDS_H

#include "boolean.h"
#include "point.h"
#include "charmachine.h"
#include "wordmachine.h"
#include "time.h"
#include "makanan.h"

void handleFoodCommand(ListMakanan l, Word aksi);
/* Menampilkan list makanan yang memiliki aksi sesuai dengan permintaan */
/* I.S. : l terdefinisi dan aksi terdefinisi */
/* F.S. : Menampilkan l dengan aksi yang sesuai permintaan dan memvalidasi input makanan yang mau dibeli. */

#endif