#include "prioqueue.h"
#include <stdio.h>

int main () {
    PrioQueue inventQ, delivQ;
    Makanan food;
    int command, hari, jam, menit, N, idx;
    boolean working;
    Word nama;
    TIME exp, deliv;
    stateNotif sn;

    MakeEmptyQ(&delivQ, 5, true);
    MakeEmptyQ(&inventQ, 5, false);
    createEmptySN(&sn);

    working = true;

    while (working) {
        printf("List command:\n");
        printf("1. Delivery\n");
        printf("2. Update queue berdasarkan waktu\n");
        printf("3. Ambil dari inventory\n");
        printf("4. Selesai\n");

        printf("\nPilih command: ");
        STARTWORD();
        command = wordToInt(currentWord);

        if (command == 1) {
            printf("\nMasukkan data makanan: \n");
            printf("ID : "); 
            STARTWORD();
            id(food) = wordToInt(currentWord);

            printf("Nama : "); 
            STARTWORD();
            nama(food) = CopyPaste(currentWord);

            printf("Waktu expired (<hari> <jam> <menit>) : ");
            STARTWORD();
            hari = wordToInt(currentWord);
            ADVWORD();
            jam = wordToInt(currentWord);
            ADVWORD();
            menit = wordToInt(currentWord);
            CreateTime(&expired(food), hari, jam, menit);

            printf("Waktu aksi (<hari> <jam> <menit>): ");
            STARTWORD();
            hari = wordToInt(currentWord);
            ADVWORD();
            jam = wordToInt(currentWord);
            ADVWORD();
            menit = wordToInt(currentWord);
            CreateTime(&actionTime(food), hari, jam, menit);

            printf("Aksi : "); 
            STARTWORD();
            aksi(food) = CopyPaste(currentWord);

            if (!IsFull(delivQ)) {
                Enqueue(&delivQ, food);
            } else {
                expandPrioQueue(&delivQ, 5);
                Enqueue(&delivQ, food);
            }

            printf("Enqueue berhasil.\n");
        } else if (command == 2) {
            printf("\nJumlah waktu (menit): ");
            STARTWORD();
            N = wordToInt(currentWord);

            updateAllQueue(&delivQ, &inventQ, N, &sn);
            printf("Update berhasil.\n");
        } else if (command == 3) {
            printf("\nNama makanan : "); 
            STARTWORD();
            nama = CopyPaste(currentWord);
            idx = indexOfName(inventQ, nama);

            if (idx != Nil) {
                deleteAtAdr(&inventQ, idx, &food);
                printf("\n\nData makanan yang diambil: \n");
                printf("ID : %d\n", id(food)); 

                printf("Nama : "); 
                printWord(nama(food));
                printf("\n");

                printf("Waktu expired : ");
                TulisTIME(expired(food));
                printf("\n");
            
                printf("Waktu aksi : ");
                TulisTIME(actionTime(food));
                printf("\n");
            
                printf("Aksi : "); 
                printWord(aksi(food));
                printf("\n");
            } else {
                printf("Tidak ada ");
                printWord(nama);
                printf(" di inventory.\n");
            }
        } else {
            working = false;
        }
        printf("\nSTATE QUEUE:");
        printf("\nDelivery:\n");
        if (IsEmpty(delivQ)) {
            printf("Queue kosong\n");
        } else {
            PrintPrioQueue(delivQ);
        }


        printf("\nInventory:\n");
        if (IsEmpty(inventQ)) {
            printf("Queue kosong\n");
        } else {
            PrintPrioQueue(inventQ);
        }
        printf("\n");
    }
    return 0;
}