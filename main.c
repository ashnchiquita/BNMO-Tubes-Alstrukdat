#include "./adt/config.h"
#include "./adt/commands.h"
#include "./adt/simulator.h"
#include "./adt/time.h"
#include "./adt/point.h"

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
    ListMakanan listMakanan, buy;
    POINT lokasiPemain;
    Makanan temp;

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

        printf("Masukkan nama pertama anda : \n");
        STARTINPUT();
        createSimulator(&pemain,lokasiPemain, currentWord);
        CreateTime(&waktuGame, 0, 0, 0);
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
                if (EndWord) {                 
                    buy = pengelompokanMakanan(listMakanan, strToWord("Buy"));
                    printCommand(buy, strToWord("Buy"));
                    printf("Enter command: \n");
                    STARTWORD();

                    while(!isFound(buy, wordToInt(currentWord) - 1) && wordToInt(currentWord) != 0){
                        printf("Nomor makanan tidak terdapat, silakan masukan input lagi\n");
                        printCommand(buy, strToWord("Buy"));
                        printf("Enter command: \n");
                        STARTWORD();
                    }

                    if(isFound(buy,wordToInt(currentWord)-1)){
                        temp = ELMT(buy,wordToInt(currentWord) - 1);
                        printf("dapet");
                        NextMenit(&waktuGame);
                        /* Push ke dalam delivery list (lagi nunggu kelar)*/
                    }

                } else {
                    valid = false;
                }
            } else if (wordEqual(currentWord, strToWord("DELIVERY"))) {
                ADVWORD();
                if (EndWord) {
                    NextMenit(&waktuGame);

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