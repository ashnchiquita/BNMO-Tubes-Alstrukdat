#ifndef NOTIF_H
#define NOTIF_H
#define NOTIF_CAP 30

#include "wordmachine.h"

typedef struct {
    WordList command;
    WordList exp;
    WordList deliv;
} stateNotif;

void createEmptySN(stateNotif * sn); 

void printNotif(stateNotif sn, int mode);

void addCommandArgs(stateNotif * sn, Word actArgs);

void setCommandArgs(stateNotif * sn, WordList command);

void addExpNotif(stateNotif * sn, Word expFoodName);

void addDelivNotif(stateNotif * sn, Word delivFoodName);

stateNotif copySN(WordList wl);

#endif