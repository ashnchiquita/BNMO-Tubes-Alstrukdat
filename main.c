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
    boolean command;
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
        listMakanan = *configMakananP();
        MakeEmptyQ(&Delivery,100,true);
        MakeEmptyQ(&Inventory,100,false);
        printf("Masukkan nama pertama anda : \n");
        STARTINPUT();
        createSimulator(&pemain,lokasiPemain, currentWord);
        CreateTime(&waktuGame, 0, 0, 0);
        treeResep = *populateResepFromFile(listMakanan, "./adt/config-r.txt");
        printf("Konfigurasi selesai, selamat bermain ");
        printWord(namaPemain(pemain));
        printf("!\n");
    } else if (wordEqual(currentWord, strToWord("EXIT"))) {
        started = false;
    }

    while (started) {
        command = false;
        finishDelivery(&Delivery,&Inventory);
        tampilanLayar(pemain,waktuGame);
        printf("Enter Command: ");
        STARTWORD();
        if (!EndWord) {
            /* Handling input normal */
            if (wordEqual(currentWord, strToWord("MIX"))) {
                ADVWORD();
                if (EndWord) {
                    ListMakanan Mix = pengelompokanMakanan(listMakanan, strToWord("Mix"));
                    printCommand(Mix,strToWord("Mix"));

                    /* CODE FRY */
                    printf("Enter command: \n");
                    STARTWORD();

                     /* Memvalidasi input user mengenai makanan mana yang mau dibeli */
                    handleFoodCommand(Mix);

                    /* CODE Mix */
                    /*Mencari nama makanan yang mau dibeli nyimpan dalam variabel temp*/
                    if(isFound(Mix,wordToInt(currentWord)-1)){
                        temp = ELMT(Mix,wordToInt(currentWord) - 1);

                        handleFoodAction(treeResep,Inventory,&command,temp);
                    };

                } else {
                    valid = false;
                }
            } else if (wordEqual(currentWord, strToWord("CHOP"))) {
                ADVWORD();
                if (EndWord) {

                    /* CODE CHOP */
                    ListMakanan Chop = pengelompokanMakanan(listMakanan, strToWord("Chop"));
                    printCommand(Chop,strToWord("Chop"));

                    printf("Enter command : \n");
                    STARTWORD();

                    handleFoodCommand(Chop);

                    if(isFound(Chop,wordToInt(currentWord)-1)){
                        temp = ELMT(Chop,wordToInt(currentWord) - 1);

                        handleFoodAction(treeResep,Inventory,&command,temp);
                    };

                } else {
                    valid = false;
                }
            } else if (wordEqual(currentWord, strToWord("FRY"))) {
                ADVWORD();
                if (EndWord) {

                    /*Mencari list makanan yang memiliki aksi Fry */
                    ListMakanan Fry = pengelompokanMakanan(listMakanan, strToWord("Fry"));
                    printCommand(Fry,strToWord("Fry"));

                    /* CODE FRY */
                    printf("Enter command: \n");
                    STARTWORD();

                     /* Memvalidasi input user mengenai makanan mana yang mau dibeli */
                    handleFoodCommand(Fry);

                    /*Mencari nama makanan yang mau dibeli nyimpan dalam variabel temp*/
                    if(isFound(Fry,wordToInt(currentWord)-1)){
                        temp = ELMT(Fry,wordToInt(currentWord) - 1);

                        handleFoodAction(treeResep,Inventory,&command,temp);
                    };

                } else {
                    valid = false;
                }
            } else if (wordEqual(currentWord, strToWord("BOIL"))) {
                ADVWORD();
                if (EndWord) {
                    /*Mencari list makanan yang memiliki aksi Fry */
                    ListMakanan Boil = pengelompokanMakanan(listMakanan, strToWord("Boil"));
                    printCommand(Boil,strToWord("Boil"));

                    /* CODE FRY */
                    printf("Enter command: \n");
                    STARTWORD();

                     /* Memvalidasi input user mengenai makanan mana yang mau dibeli */
                    handleFoodCommand(Boil);

                    /* CODE BOIL */
                    /*Mencari nama makanan yang mau dibeli nyimpan dalam variabel temp*/
                    if(isFound(Boil,wordToInt(currentWord)-1)){
                        temp = ELMT(Boil,wordToInt(currentWord) - 1);

                        handleFoodAction(treeResep,Inventory,&command,temp);
                    };
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
                    printMakanan(listMakanan);

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
                        temp = ELMT(buy,wordToInt(currentWord) - 1);

                        /*Menampilkan notifikasi bahwa pembelian berhasil */
                        notifikasiPembelian(temp);

                        /*Menambahkan makanan ke delivery list */
                        Enqueue(&Delivery,temp);
                        command = true;
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
                                    updateAllQueue(&Delivery,&Inventory,(waitX*60 + waitY));
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
            }else {
                valid = false;
            }
        } else {
            valid = false;
        }
        
        if (!valid) {
            printf("Command tidak valid.\nUntuk melihat list command dan keterangannya, silakan masukkan command 'HELP'.");
        }

        /*Kalau misalnya commandnya valid, update 1 menit ke delivery, inventory, dan waktu game*/
        if(command){
            update1Min(&Delivery);
            update1Min(&Inventory);
            NextMenit(&waktuGame);
        }
        
    }

    /* End Screen (congrats, win/lose, stats) */

    return 0;
}