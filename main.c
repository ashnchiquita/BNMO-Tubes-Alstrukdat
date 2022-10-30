#include "./adt/config.h"
#include "./adt/commands.h"
#include "./adt/simulator.h"
#include "./adt/time.h"
#include "./adt/point.h"
#include "./adt/prioqueue.h"
#include "adt/tree.h"

void tampilanLayar(Simulator pemain, TIME waktuMain){
    printWord(namaPemain(pemain));
    printf(" di posisi : ");
    TulisPOINT(lokasiPemain(pemain));
    printf("\n");
    printf("Waktu : %d.%d\n",Jam(waktuMain),Menit(waktuMain));
    /* tampilkan notifikasi dan peta kalo udah ada */
}

int main() {
    /* KAMUS */
    boolean started, valid;
    int waitX, waitY;
    Word moveDirection, nama, pilihan;
    Simulator pemain;
    TIME waktuGame;
    boolean changeTime;
    ListMakanan listMakanan, buy;
    POINT lokasiPemain;
    Makanan temp;
    PrioQueue Delivery, Inventory;
    ListTree treeResep;
    /* ALGORITMA */

    /* splash screen nyusul */

    printf("Silakan masukkan command (START/EXIT): ");
    STARTWORD();

    if (EndWord) {
        valid = false;
    } else {
        valid = wordEqual(currentWord, strToWord("START")) || wordEqual(currentWord, strToWord("EXIT"));
    }

    while (!valid) {
        printf("Silakan masukkan command yang valid.\n");
        STARTWORD();

        if (EndWord) {
            valid = false;
        } else {
            valid = wordEqual(currentWord, strToWord("START")) || wordEqual(currentWord, strToWord("EXIT"));
        }
    }

    if (wordEqual(currentWord, strToWord("START"))) {
        started = true;

        /*Kalau udah config peta, tolong disimpen di lokasiPemain*/
        /*createPoint(&lokasiPemain,x,y)*/
        listMakanan = configMakanan();
        MakeEmptyQ(&Delivery,100,true);
        MakeEmptyQ(&Inventory,100,false);
        printf("Masukkan nama pertama anda : \n");
        STARTINPUT();
        createSimulator(&pemain,lokasiPemain, currentWord);
        CreateTime(&waktuGame, 0, 0, 0);
        treeResep = *populateResepFromFile(listMakanan, "adt/config-r.txt");
        printf("Konfigurasi selesai, selamat bermain ");
        printWord(namaPemain(pemain));
        printf("!\n");
        tampilanLayar(pemain,waktuGame);
    } else if (wordEqual(currentWord, strToWord("EXIT"))) {
        started = false;
    }

    while (started) {
        tampilanLayar(pemain,waktuGame);
        printf("Enter Command: ");
        STARTWORD();
        if (!EndWord) {
            changeTime = false;
            /* Handling input normal */
            if (wordEqual(currentWord, strToWord("MIX"))) {
                ADVWORD();
                if (EndWord) {
                    NextMenit(&waktuGame);

                    /* CODE MIX */

                } else {
                    valid = false;
                }
            } else if (wordEqual(currentWord, strToWord("CHOP"))) {
                ADVWORD();
                if (EndWord) {
                    NextMenit(&waktuGame);

                    /* CODE CHOP */

                } else {
                    valid = false;
                }
            } else if (wordEqual(currentWord, strToWord("FRY"))) {
                ADVWORD();
                if (EndWord) {
                    NextMenit(&waktuGame);
                    printMakanan(pengelompokanMakanan(listMakanan, strToWord("Fry")));

                    /* CODE FRY */

                } else {
                    valid = false;
                }
            } else if (wordEqual(currentWord, strToWord("BOIL"))) {
                ADVWORD();
                if (EndWord) {
                    NextMenit(&waktuGame);
                    printMakanan(pengelompokanMakanan(listMakanan, strToWord("Boil")));

                    /* CODE BOIL */

                } else {
                    valid = false;
                }
            } else if (wordEqual(currentWord, strToWord("UNDO"))) {
                ADVWORD();
                if (EndWord) {

                    /* CODE UNDO */

                } else {
                    valid = false;
                }
            } else if (wordEqual(currentWord, strToWord("REDO"))) {
                ADVWORD();
                if (EndWord) {

                    /* CODE REDO */

                } else {
                    valid = false;
                }
            } else if (wordEqual(currentWord, strToWord("CATALOG"))) {
                ADVWORD();
                if (EndWord) {

                    /* CODE CATALOG */

                } else {
                    valid = false;
                }
            } else if (wordEqual(currentWord, strToWord("COOKBOOK"))) {
                ADVWORD();
                if (EndWord) {

                    /* CODE COOKBOOK */

                } else {
                    valid = false;
                }
            } else if (wordEqual(currentWord, strToWord("BUY"))) {
                ADVWORD();

                /*Harus tambahin validasi lokasi dia dimana */

                if (EndWord) {                 
                    
                    /*Mencari makanan yang memiliki aksi Buy dan menampilkan listnya ke layar*/
                    buy = pengelompokanMakanan(listMakanan, strToWord("Buy"));
                    printCommand(buy, strToWord("Buy"));

                    /*Meminta input user untuk makanan mana yang mau dibeli*/
                    printf("Enter command: \n");
                    STARTWORD();

                    /* Memvalidasi input user mengenai makanan mana yang mau dibeli */
                    handleFoodCommand(buy);

                    /* Jika input user benar, maka makanan akan masuk ke delivery list dan waktu game bertambah 1 menit */
                    if(isFound(buy,wordToInt(currentWord)-1)){
                        changeTime = true;
                        temp = ELMT(buy,wordToInt(currentWord) - 1);

                        /*Menampilkan notifikasi bahwa pembelian berhasil */
                        notifikasiPembelian(temp);

                        /*Menambahkan makanan ke delivery list */
                        Enqueue(&Delivery,temp);
                        NextMenit(&waktuGame);
                    }

                } else {
                    valid = false;
                }
            } else if (wordEqual(currentWord, strToWord("DELIVERY"))) {
                ADVWORD();
                if (EndWord) {
                    PrintPrioQueue(Delivery);
                    /* CODE DELIVERY */
                } else {
                    valid = false;
                }

            /* Handling input berargumen */
            } else if (wordEqual(currentWord, strToWord("MOVE"))) {
                ADVWORD();
                if (EndWord) {
                    valid = false;
                } else {
                    if (wordEqual(currentWord, strToWord("NORTH")) || wordEqual(currentWord, strToWord("SOUTH")) || wordEqual(currentWord, strToWord("WEST")) || wordEqual(currentWord, strToWord("EAST"))) {
                        moveDirection = CopyPaste(currentWord);

                        ADVWORD();
                        if (EndWord) {
                            NextMenit(&waktuGame);

                            /* CODE MOVE (Arah disimpen di moveDirection) */

                        } else {
                            valid = false;
                        }
                    } else {
                        valid = false;
                    }
                }
            } else if (wordEqual(currentWord, strToWord("WAIT"))) {
                ADVWORD();
                if (EndWord) {
                    valid = false;
                } else {
                    if (isWordInt(currentWord)) {

                        waitX = wordToInt(currentWord);
                        ADVWORD();

                        if (EndWord) {
                            valid = false;
                        } else {
                            if (isWordInt(currentWord)) {

                                waitY = wordToInt(currentWord);
                                ADVWORD();

                                if (EndWord) {

                                    /* CODE WAIT (x disimpen di waitX, y disimpen di waitY) */
                                    handleWait(&waktuGame, waitX, waitY);
                                } else {
                                    valid = false;
                                }
                            } else {
                                valid = false;
                            }
                        }
                    } else {
                        valid = false;
                    }
                }
            } else {
                valid = false;
            }
        } else {
            valid = false;
        }
        
        if (!valid) {
            printf("Command tidak valid.\nUntuk melihat list command dan keterangannya, silakan masukkan command 'HELP'.");
        }

    }

    /* End Screen (congrats, win/lose, stats) */

    return 0;
}