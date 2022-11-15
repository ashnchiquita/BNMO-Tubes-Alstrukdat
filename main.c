#include "./adt/config.h"
#include "./adt/commands.h"
#include "./adt/simulator.h"
#include "./adt/time.h"
#include "./adt/point.h"
#include "./adt/prioqueue.h"
#include "adt/tree.h"
#include "adt/stack.h"
#include "adt/notif.h"

void tampilanLayar(Simulator pemain, TIME waktuMain, stateNotif sn, int mode){
    printf("\n");
    printWord(namaPemain(pemain));
    printf(" di posisi : ");
    TulisPOINT(lokasiPemain(pemain));
    printf("\n");
    printf("Waktu : %d.%d\n",Jam(waktuMain),Menit(waktuMain));
    printNotif(sn, mode);
}

int main() {
    /* KAMUS */
    boolean started, valid, unredo, command, wait,action;
    int waitX, waitY, updateMenit, modeNotif, actionDuration;
    Word moveDirection, nama, pilihan;
    Simulator pemain;
    TIME waktuGame;
    ListMakanan listMakanan, buy;
    POINT lokasiPemain;
    Makanan temp;
    PrioQueue Delivery, Inventory, tempQueue1, tempQueue2; 
    ListTree treeResep;
    Matrix peta;
    Stack state,redo;
    WordList act;
    stateNotif sn;

    /* ALGORITMA */

    /* Splash Screen Intro */

    printf("\n               +-++-++-++-++-++-++-+ +-++-+\n");
    printf("               |w||e||l||c||o||m||e| |t||o|\n");
    printf("               +-++-++-++-++-++-++-+ +-++-+\n");
    printf("\n");           
    printf("               .-._                 ___       _,.---._     \n");
    printf("    _..---.   /==/ \\  .-._   .-._ .'=.'\\    ,-.' , -  `.   \n");
    printf("  .' .'.-. \\  |==|, \\/ /, / /==/ \\|==|  |  /==/_,  ,  - \\  \n");
    printf(" /==/- '=' /  |==|-  \\|  |  |==|,|  / - | |==|   .=.     | \n");
    printf(" |==|-,   '   |==| ,  | -|  |==|  \\/  , | |==|_ : ;=:  - | \n");
    printf(" |==|  .=. \\  |==| -   _ |  |==|- ,   _ | |==| , '='     | \n");
    printf(" /==/- '=' ,| |==|  /\\ , |  |==| _ /\\   |  \\==\\ -    ,_ /  \n");
    printf("|==|   -   /  /==/, | |- |  /==/  / / , /   '.='. -   .'   \n");
    printf("`-._`.___,'   `--`./  `--`  `--`./  `--`      `--`--''     \n");
    printf("\n             ---* Cooking Game Simulator *---\n");
    printf("\n           Created by Kelompok H Kelas K2 IF'21\n\n");
    
    /* Validasi Input Pertama */
    do {
        valid = true;
        printf("Enter Command (START/EXIT): ");
        STARTWORD();
        if (!EndWord) {
            if (wordEqual(currentWord, strToWord("START"))) {
                ADVWORD();
                if (EndWord) {
                    started = true;

                    /* Memulai konfigurasi dengan membaca file */
                    listMakanan = *configMakananP();
                    peta = configPeta(&lokasiPemain);
                    treeResep = *populateResepFromFile(listMakanan, "./adt/config-r.txt");

                    /* Membuat list delivery dan list inventory yang menggunakan priority Queue*/
                    MakeEmptyQ(&Delivery,100,true);
                    MakeEmptyQ(&Inventory,100,false);
                    
                    /*Membuat stack yang mencatat semua state ketika program berhasil */
                    CreateEmptyStack(&state);
                    CreateEmptyStack(&redo);
                    
                    /*Meminta input nama user untuk disimpan dalam simulator */
                    printf("Masukkan nama pertama anda : \n");
                    STARTINPUT();
                    createSimulator(&pemain,lokasiPemain, currentWord);
                    CreateTime(&waktuGame, 0, 0, 0);
                    createEmptySN(&sn);
                    createWL(&act);
                    modeNotif = 1;

                    states init = {waktuGame,lokasiPemain,Delivery,Inventory,sn};
                    PushStack(&state,init);
                
                    /*Ucapan selamat bermain untuk peserta */
                    printf("Konfigurasi selesai, selamat bermain ");
                    printWord(namaPemain(pemain));
                    printf("!\n");

                    /*Selalu menampilkan peta, lokasi pemain, waktu game, dan notifikasi ke layaar*/
                    tampilanLayar(pemain,waktuGame, sn, modeNotif);
                    displayPeta(peta);
                } else {
                    valid = false;
                }
            } else if (wordEqual(currentWord, strToWord("EXIT"))) {
                ADVWORD();
                if (EndWord) {
                    started = false;
                } else {
                    valid = false;
                }
            } else {
                valid = false;
            }
        } else {
            valid = false;
        }
        if (!valid) {
            printf("Silakan masukkan command yang valid.\n");
            untilEndWord();
        }
    } while (!valid);

    /* Commands Game */
    while (started) {
        command = false;
        wait = false;
        valid = true;
        action = false;

        printf("Enter Command: ");
        STARTWORD();
        if (!EndWord) {
            /* MIX */
            if (wordEqual(currentWord, strToWord("MIX"))) {
                appendWL(CopyPaste(currentWord), &act);
                ADVWORD();
                if (EndWord) {
                    if(isLocAdjacent(peta,pemain,'M')){
                        ListMakanan Mix = pengelompokanMakanan(listMakanan, strToWord("Mix"));
                        printCommand(Mix,strToWord("Mix"));

                        printf("Enter command: \n");
                        STARTWORD();

                        /* Memvalidasi input user mengenai makanan mana yang mau dibeli */
                        handleFoodCommand(Mix);

                        /* CODE Mix */
                        /*Mencari nama makanan yang mau dibeli nyimpan dalam variabel temp*/
                        if(isFound(Mix,wordToInt(currentWord)-1)){
                            temp = ELMT(Mix,wordToInt(currentWord) - 1);
                            
                            // TulisTIME(actionTime(temp));
                            handleFoodAction(treeResep,&Inventory,&action,temp);
                            setCommandArgs(&sn, act);
                        };
                    }else{
                        printf("BNMO tidak berada di area Mix\n");
                    }
                } else {
                    valid = false;
                }
            
            /* CHOP */
            } else if (wordEqual(currentWord, strToWord("CHOP"))) {
                appendWL(CopyPaste(currentWord), &act);
                ADVWORD();
                if (EndWord) {
                    if(isLocAdjacent(peta,pemain,'C')){
                        ListMakanan Chop = pengelompokanMakanan(listMakanan, strToWord("Chop"));
                        printCommand(Chop,strToWord("Chop"));

                        printf("Enter command : \n");
                        STARTWORD();

                        handleFoodCommand(Chop);

                        if(isFound(Chop,wordToInt(currentWord)-1)){
                            temp = ELMT(Chop,wordToInt(currentWord) - 1);
                            
                            handleFoodAction(treeResep,&Inventory,&action,temp);
                            setCommandArgs(&sn, act);
                            updateMenit = TIMEToMenit(actionTime(temp));  
                        };
                    }else{
                        printf("BNMO tidak berada di area Chop\n");
                    }
                } else {
                    valid = false;
                }

            /* FRY */
            } else if (wordEqual(currentWord, strToWord("FRY"))) {
                appendWL(CopyPaste(currentWord), &act);
                ADVWORD();
                if (EndWord) {
                    if(isLocAdjacent(peta,pemain,'F')){
                        /*Mencari list makanan yang memiliki aksi Fry */
                        ListMakanan Fry = pengelompokanMakanan(listMakanan, strToWord("Fry"));
                        printCommand(Fry,strToWord("Fry"));

                        printf("Enter command: \n");
                        STARTWORD();

                        /* Memvalidasi input user mengenai makanan mana yang mau dibeli */
                        handleFoodCommand(Fry);

                        /*Mencari nama makanan yang mau dibeli nyimpan dalam variabel temp*/
                        if(isFound(Fry,wordToInt(currentWord)-1)){
                            temp = ELMT(Fry,wordToInt(currentWord) - 1);

                            handleFoodAction(treeResep,&Inventory,&action,temp);
                            setCommandArgs(&sn, act);
                        };
                    }else{
                        printf("BNMO tidak berada di area Fry\n");
                    }
                    
                } else {
                    valid = false;
                }

            /* BOIL */
            } else if (wordEqual(currentWord, strToWord("BOIL"))) {
                appendWL(CopyPaste(currentWord), &act);
                ADVWORD();
                if (EndWord) {
                    if(isLocAdjacent(peta,pemain,'B')){
                        ListMakanan Boil = pengelompokanMakanan(listMakanan, strToWord("Boil"));
                        printCommand(Boil,strToWord("Boil"));

                        printf("Enter command: \n");
                        STARTWORD();

                        /* Memvalidasi input user mengenai makanan mana yang mau dibeli */
                        handleFoodCommand(Boil);

                        /* CODE BOIL */
                        /*Mencari nama makanan yang mau dibeli nyimpan dalam variabel temp*/
                        if(isFound(Boil,wordToInt(currentWord)-1)){
                            temp = ELMT(Boil,wordToInt(currentWord) - 1);

                            handleFoodAction(treeResep,&Inventory,&action,temp);
                            setCommandArgs(&sn, act);
                        };
                    }else{
                        printf("BNMO tidak berada di area BOIL\n");
                    }
                } else {
                    valid = false;
                }
            /* UNDO */
            } else if (wordEqual(currentWord, strToWord("UNDO"))) {
                ADVWORD();
                if (EndWord) {
                    UNDO(&state,&redo,&waktuGame,&pemain.lokasi,&Delivery,&Inventory, &sn);
                    fixedDisplay(&peta,pemain);
                    modeNotif = 2;
                    unredo = true;
                    
                } else {
                    valid = false;
                }

            /* REDO */
            } else if (wordEqual(currentWord, strToWord("REDO"))) {
                ADVWORD();
                if (EndWord) {
                    REDO(&state,&redo,&waktuGame,&pemain.lokasi,&Delivery,&Inventory, &sn);
                    fixedDisplay(&peta,pemain);
                    modeNotif = 3;
                    unredo = true;
                } else {
                    valid = false;
                }

            /* CATALOG */
            } else if (wordEqual(currentWord, strToWord("CATALOG"))) {
                ADVWORD();
                if (EndWord) {
                    printMakanan(listMakanan);
                } else {
                    valid = false;
                }

            /* COOKBOOK */
            } else if (wordEqual(currentWord, strToWord("COOKBOOK"))) {
                ADVWORD();
                if (EndWord) {

                    /* CODE COOKBOOK */

                } else {
                    valid = false;
                }
            
            /* BUY */
            } else if (wordEqual(currentWord, strToWord("BUY"))) {
                appendWL(CopyPaste(currentWord), &act);
                ADVWORD();

                if (EndWord) {                 
                    if(isLocAdjacent(peta,pemain,'T')){
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
                            appendWL(CopyPaste(nama(temp)), &act);
                            /*Menampilkan notifikasi bahwa pembelian berhasil */
                            notifikasiPembelian(temp);
                            setCommandArgs(&sn, act);
                            /*Menambahkan makanan ke delivery list */
                            Enqueue(&Delivery,temp);
                            
                            command = true;
                        }
                    }else{
                        printf("BNMO tidak berada di area telepon!\n");
                    }
                } else {
                    valid = false;
                }

            /* INVENTORY */
            } else if(wordEqual(currentWord, strToWord("INVENTORY"))){
                ADVWORD();
                if(EndWord){
                    if (IsEmpty(Inventory)) {
                        printf("Tidak ada makanan di inventory\n");
                    } else {
                        printf("List Makanan di Inventory\n(nama - waktu sisa kedaluarsa)\n");
                        PrintPrioQueue(Inventory);
                    }
                }

            /* DELIVERY */
            } else if (wordEqual(currentWord, strToWord("DELIVERY"))) {
                ADVWORD();
                if (EndWord) {
                    if (IsEmpty(Delivery)) {
                        printf("Tidak ada makanan di perjalanan\n");
                    } else {
                        printf("List Makanan di Perjalanan\n(nama - waktu sisa delivery)\n");
                        PrintPrioQueue(Delivery);
                    }
                } else {
                    valid = false;
                }

            /* MOVE */
            } else if (wordEqual(currentWord, strToWord("MOVE"))) {
                appendWL(CopyPaste(currentWord), &act);
                ADVWORD();
                if (EndWord) {
                    valid = false;
                } else {
                    if (wordEqual(currentWord, strToWord("NORTH")) || wordEqual(currentWord, strToWord("SOUTH")) || wordEqual(currentWord, strToWord("WEST")) || wordEqual(currentWord, strToWord("EAST"))) {
                        moveDirection = CopyPaste(currentWord);
                        appendWL(CopyPaste(currentWord), &act);

                        ADVWORD();
                        if (EndWord) {
                            setCommandArgs(&sn, act);
                            /* CODE MOVE (Arah disimpen di moveDirection) */
                            if (moveDirection.TabWord[0] == 'N' || moveDirection.TabWord[0] == 'n') {
                                moveNorth(&peta, &pemain, &command);
                            } else if (moveDirection.TabWord[0] == 'S' || moveDirection.TabWord[0] == 's') {
                                moveSouth(&peta, &pemain, &command);
                            } else if (moveDirection.TabWord[0] == 'W'|| moveDirection.TabWord[0] == 'w') {
                                moveWest(&peta, &pemain, &command);
                            } else if (moveDirection.TabWord[0] == 'E' || moveDirection.TabWord[0] == 'e') {
                                moveEast(&peta, &pemain, &command);
                            }

                        } else {
                            valid = false;
                        }
                    } else {
                        valid = false;
                    }
                }
            
            /* EXIT */
            } else if (wordEqual(currentWord, strToWord("EXIT"))) {
                ADVWORD();
                if (EndWord) {
                    started = false;
                } else {
                    valid = false;
                }
            
            /* HELP */
            } else if (wordEqual(currentWord, strToWord("HELP"))) {
                ADVWORD();
                if (EndWord) {
                    printf("\n\n-------------------- *** : : ---* Guide Commands *--- : : *** --------------------");
                    printf("\n|                                                                                |");
                    printf("\n|  START       : Memulai game                                                    |");
                    printf("\n|  BUY         : Memesan bahan makanan                                           |");
                    printf("\n|  MIX         : Mencampurkan dua atau lebih makanan menjadi satu makanan        |");
                    printf("\n|  CHOP        : Memotong satu bahan makanan menjadi bahan yang sudah terpotong  |");
                    printf("\n|  FRY         : Menggoreng satu atau lebih bahan makanan                        |");
                    printf("\n|  BOIL        : Merebus satu bahan makanan                                      |");
                    printf("\n|  MOVE NORTH  : Menggerakkan simulator BNMO satu satuan ke arah utara           |");
                    printf("\n|  MOVE SOUTH  : Menggerakkan simulator BNMO satu satuan ke arah selatan         |");
                    printf("\n|  MOVE EAST   : Menggerakkan simulator BNMO satu satuan ke arah timur           |");
                    printf("\n|  MOVE WEST   : Menggerakkan simulator BNMO satu satuan ke arah barat           |");
                    printf("\n|  WAIT x y    : Menunggu selama x jam dan y menit tanpa melakukan apa-apa       |");
                    printf("\n|  CATALOG     : Menampilkan bahan dan makanan yang tersedia pada aplikasi       |");
                    printf("\n|  COOKBOOK    : Menampilkan resep-resep yang tersedia pada sistem               |");
                    printf("\n|  INVENTORY   : Menampilkan inventory makanan milik pengguna                    |");
                    printf("\n|  DELIVERY    : Menampilkan delivery list                                       |");
                    printf("\n|  UNDO        : Membatalkan command yang dilakukan sebelumnya                   |");
                    printf("\n|  REDO        : Membatalkan command UNDO                                        |");
                    printf("\n|  HELP        : Menampilkan guide command kepada pengguna                       |");
                    printf("\n|  KULKAS      : Menyimpan makanan di kulkas                                     |");
                    printf("\n|  REKOMENDASI : Menampilkan rekomendasi makanan yang dapat dibuat               |");
                    printf("\n|  AUTO BNMO   : Memainkan BNMO secara otomatis                                  |");
                    printf("\n|  EXIT        : Keluar dari game                                                |");
                    printf("\n|                                                                                |");
                    printf("\n----------------------------------------------------------------------------------\n\n");
                } else {
                    valid = false;
                }
            
            /* WAIT */
            } else if (wordEqual(currentWord, strToWord("WAIT"))) {
                appendWL(CopyPaste(currentWord), &act);
                ADVWORD();
                if (EndWord) {
                    valid = false;
                } else {
                    if (isWordInt(currentWord)) {
                        appendWL(CopyPaste(currentWord), &act);
                        waitX = wordToInt(currentWord);
                        ADVWORD();

                        if (EndWord) {
                            valid = false;
                        } else {
                            if (isWordInt(currentWord)) {

                                waitY = wordToInt(currentWord);
                                appendWL(CopyPaste(currentWord), &act);
                                ADVWORD();

                                if (EndWord) {
                                    wait = true;
                                    updateMenit = waitX * 60 + waitY;
                                    setCommandArgs(&sn, act);
                                   
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
            printf("Command tidak valid.\nUntuk melihat list command dan keterangannya, silakan masukkan command 'HELP'.\n");
            untilEndWord();
        }

        /*Kalau misalnya commandnya valid, update 1 menit ke delivery, inventory, dan waktu game*/
        if(command){
            update1Min(&Delivery);
            update1Min(&Inventory);
            NextMenit(&waktuGame);
            setCommandArgs(&sn, act);
            finishDelivery(&Delivery,&Inventory, &sn);
            cleanKedaluarsa(&Inventory, &sn);
            states tempState = {waktuGame,pemain.lokasi,Delivery,Inventory, sn};
            PushStack(&state,tempState);
        }else if(wait){
            /*Mengcopy Delivery dan Inventory ke temp1 dan temp2*/
            copyPrioQueue(Delivery,&tempQueue1);
            copyPrioQueue(Inventory,&tempQueue2);

            /*Mengupdate waktu sesuai menit yang di wait*/
            updateAllQueue(&tempQueue1,&tempQueue2,updateMenit, &sn);

            /*Mengcopy kembali temp1 ke delivery dan temp2 ke inventory*/
            copyPrioQueue(tempQueue1,&Delivery);
            copyPrioQueue(tempQueue2,&Inventory);

            /* Menambahkan N menit waktu ke dalam waktu game */
            NextNMenit(&waktuGame,updateMenit);
            states tempState = {waktuGame,pemain.lokasi,tempQueue1,tempQueue2, sn};
            /* Push States ke dalam stack */
            PushStack(&state,tempState);

        }else if(action){
            
            /*Mengcopy Delivery dan Inventory ke temp1 dan temp2*/
            copyPrioQueue(Delivery,&tempQueue1);
            copyPrioQueue(Inventory,&tempQueue2);
            
            /*Mengupdate waktu sesuai menit yang di wait*/
            updateAllQueue(&tempQueue1,&tempQueue2,updateMenit, &sn);

            /* Menambahkan makanan yang sudah dibuat ke dalam inventory */
            addingFood(temp,&tempQueue2,treeResep,&act,&sn);
            setCommandArgs(&sn, act);

            /*Mengcopy kembali temp1 ke delivery dan temp2 ke inventory*/
            copyPrioQueue(tempQueue1,&Delivery);
            copyPrioQueue(tempQueue2,&Inventory);

            /* Menambahkan N menit waktu ke dalam waktu game */
            NextNMenit(&waktuGame,updateMenit);
            states tempState = {waktuGame,pemain.lokasi,tempQueue1,tempQueue2, sn};
            /* Push States ke dalam stack */
            PushStack(&state,tempState);
        }   
        /*Selalu menampilkan peta, lokasi pemain, waktu game, dan notifikasi ke layaar*/
        if (started) {
            tampilanLayar(pemain, waktuGame, sn, modeNotif);
            displayPeta(peta);
            modeNotif = 1;
            if (command || wait || unredo) {
                createEmptySN(&sn);
                createWL(&act);
            }
        }
    }

    /* Splash Screen Outro */
    if (!started) {
        printf("\n                    THANKS FOR USING\n");
        printf("               .-._                 ___       _,.---._     \n");
        printf("    _..---.   /==/ \\  .-._   .-._ .'=.'\\    ,-.' , -  `.   \n");
        printf("  .' .'.-. \\  |==|, \\/ /, / /==/ \\|==|  |  /==/_,  ,  - \\  \n");
        printf(" /==/- '=' /  |==|-  \\|  |  |==|,|  / - | |==|   .=.     | \n");
        printf(" |==|-,   '   |==| ,  | -|  |==|  \\/  , | |==|_ : ;=:  - | \n");
        printf(" |==|  .=. \\  |==| -   _ |  |==|- ,   _ | |==| , '='     | \n");
        printf(" /==/- '=' ,| |==|  /\\ , |  |==| _ /\\   |  \\==\\ -    ,_ /  \n");
        printf("|==|   -   /  /==/, | |- |  /==/  / / , /   '.='. -   .'   \n");
        printf("`-._`.___,'   `--`./  `--`  `--`./  `--`      `--`--''     \n");
        printf("\n             ---* Cooking Game Simulator *---\n");
        printf("\n           Created by Kelompok H Kelas K2 IF'21\n\n");
    }

    return 0;
}

