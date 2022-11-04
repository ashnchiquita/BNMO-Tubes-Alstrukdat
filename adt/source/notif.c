#include "../notif.h"
#include <stdio.h>

void createEmptySN(stateNotif * sn) {
    createWL(&((*sn).command));
    createWL(&((*sn).exp));
    createWL(&((*sn).deliv));
}

void printNotif(stateNotif sn, int mode) {
    printf("Notifikasi:\n");
    /* Mode Normal */
    if (mode == 1) {
        /* Expired */
        if (!isEmptyWL(sn.exp)) {
            printWL(sn.exp, ", ");
            printf(" kedaluarsa\n");
        }

        /* Delivered */
        if (!isEmptyWL(sn.deliv)) {
            printWL(sn.deliv, ", ");
            printf(" sudah sampai dari perjalanan\n");
        }

        if(isEmptyWL(sn.exp) && isEmptyWL(sn.deliv)) {
            printf("-");
        }
    /* Mode UNDO */
    } else if (mode == 2) {
        /* Aksi */
        printf("Aksi ");
        printWL(sn.command, " ");
        printf(" dibatalkan\n");

        /* Expired */
        if (!isEmptyWL(sn.exp)) {
            printWL(sn.exp, ", ");
            printf(" dikembalikan ke inventory\n");
        }

        /* Delivered */
        if (!isEmptyWL(sn.deliv)) {
            printWL(sn.deliv, ", ");
            printf(" dikembalikan ke perjalanan\n");
        }
    /* Mode REDO */
    } else if (mode == 3) {
        /* Aksi */
        printf("Aksi ");
        printWL(sn.command, " ");
        printf(" dilakukan ulang\n");

        /* Expired */
        if (!isEmptyWL(sn.exp)) {
            printWL(sn.exp, ", ");
            printf(" kedaluarsa\n");
        }

        /* Delivered */
        if (!isEmptyWL(sn.deliv)) {
            printWL(sn.deliv, ", ");
            printf(" sudah sampai dari perjalanan\n");
        }
    }
}

void addCommandArgs(stateNotif * sn, Word actArgs) {
    appendWL(actArgs, &(*sn).command);
}

void setCommandArgs(stateNotif * sn, WordList command) {
    (*sn).command = command;
}

void addExpNotif(stateNotif * sn, Word expFoodName) {
    appendWL(expFoodName, &(*sn).exp);
}

void addDelivNotif(stateNotif * sn, Word delivFoodName) {
    appendWL(delivFoodName, &(*sn).deliv);
}
