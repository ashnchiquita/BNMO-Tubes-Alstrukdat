#ifndef NOTIF_H
#define NOTIF_H
#define NOTIF_CAP 30

#include "wordmachine.h"

typedef struct {
    WordList command;
    WordList exp;
    WordList deliv;
} stateNotif;

boolean isEmptySN(stateNotif sn);
/* Mengembalikan nilai benar, jika kulkas kosong */

void createEmptySN(stateNotif * sn); 
/* Membuat kulkas kosong */

void printNotif(stateNotif sn, int mode);
/* I.S. : Sembarang*/
/* F.S. : Mencetak notifikasi ke layar */

void addCommandArgs(stateNotif * sn, Word actArgs);
/* I.S. : sn terdefinisi */
/* F.S. : Menambahkan notifikasi ke dalam stateNotif sn */

void setCommandArgs(stateNotif * sn, WordList command);
/* I.S. : sn terdefinisi */
/* F.S. : Mengcopy command dan memasukannya ke sn */

void addExpNotif(stateNotif * sn, Word expFoodName);
/* I.S. : sn terdefinisi */
/* F.S. : Menampilkan notif makanan expired*/

void addDelivNotif(stateNotif * sn, Word delivFoodName);
/* I.S. : sn terdefinisi */
/* F.S. : Menampilkan notifikasi delivery */

stateNotif copySN(stateNotif sn);
/* Mengembalikan suatu salinan dari sn */

#endif