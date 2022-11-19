#ifndef COMMANDS_H
#define COMMANDS_H

#include "../boolean.h"
#include "../Point/point.h"
#include "../Charmachine/charmachine.h"
#include "../Wordmachine/wordmachine.h"
#include "../Time/time.h"
#include "../Makanan/makanan.h"
#include "../Tree/tree.h"
#include "../Notifikasi/notif.h"

void handleFoodCommand(ListMakanan l);
/* Menampilkan list makanan yang memiliki aksi sesuai dengan permintaan */
/* I.S. : l terdefinisi dan aksi terdefinisi */
/* F.S. : Menampilkan l dengan aksi yang sesuai permintaan dan memvalidasi input makanan yang mau dibeli. */

void notifikasiPembelian(Makanan l);

void notifikasiGoreng(Makanan m);

void notifikasiGagal(ListMakanan m);

void handleFoodAction(ListTree treeResep, PrioQueue * Inventory, boolean *command,Makanan temp);

void addingFood(Makanan temp, PrioQueue *Inventory, ListTree treeResep,WordList *act, stateNotif *sn);

#endif