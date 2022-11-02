#include "./adt/config.h"
#include "./adt/commands.h"
#include "./adt/simulator.h"
#include "./adt/time.h"
#include "./adt/point.h"
#include "./adt/prioqueue.h"
#include "adt/tree.h"
#include "adt/stack.h"

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
    int waitX, waitY,updateMenit;
    Word moveDirection, nama, pilihan;
    Simulator pemain;
    TIME waktuGame;
    boolean command,wait;
    ListMakanan listMakanan, buy;
    POINT lokasiPemain;
    Makanan temp;
    PrioQueue Delivery, Inventory;
    ListTree treeResep;
    Matrix peta;
    Stack state,redo;
    /* ALGORITMA */

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

    printf("Silakan masukkan command (START/EXIT): ");
    STARTWORD();

    if (EndWord) {
        valid = false;
    } else {
        valid = wordEqual(currentWord, strToWord("START")) || wordEqual(currentWord, strToWord("EXIT"));
    }

    while (!valid) {
        printf("Silakan masukkan command yang valid.\n");
        printf("Silakan masukkan command (START/EXIT): ");
        STARTWORD();

        if (EndWord) {
            valid = false;
        } else {
            valid = wordEqual(currentWord, strToWord("START")) || wordEqual(currentWord, strToWord("EXIT"));
        }
    }

    if (wordEqual(currentWord, strToWord("START"))) {
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
        states init = {waktuGame,lokasiPemain,Delivery,Inventory};
        PushStack(&state,init);
    
        /*Ucapan selamat bermain untuk peserta */
        printf("Konfigurasi selesai, selamat bermain ");
        printWord(namaPemain(pemain));
        printf("!\n");
    } else if (wordEqual(currentWord, strToWord("EXIT"))) {
        started = false;
    }

    while (started) {
        command = false;
        wait = false;
        valid = true;
        /*Selalu menampilkan peta, lokasi pemain, waktu game, dan notifikasi ke layaar*/
        tampilanLayar(pemain,waktuGame);
        displayPeta(peta);
        
        /*Meminta input user */
        printf("Enter Command: ");
        STARTWORD();
        if (!EndWord) {
            /* Handling input normal */
            if (wordEqual(currentWord, strToWord("MIX"))) {
                ADVWORD();
                if (EndWord) {
                    if(isLocAdjacent(peta,pemain,'M')){
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
                    }else{
                        printf("BNMO tidak berada di area Mix");
                    }
                } else {
                    valid = false;
                }
            } else if (wordEqual(currentWord, strToWord("CHOP"))) {
                ADVWORD();
                if (EndWord) {
                    if(isLocAdjacent(peta,pemain,'C')){
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
                    }else{
                        printf("BNMO tidak berada di area Chop");
                    }
                } else {
                    valid = false;
                }
            } else if (wordEqual(currentWord, strToWord("FRY"))) {
                ADVWORD();
                if (EndWord) {
                    if(isLocAdjacent(peta,pemain,'F')){
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
                    }else{
                        printf("BNMO tidak berada di area Fry");
                    }
                    
                } else {
                    valid = false;
                }
            } else if (wordEqual(currentWord, strToWord("BOIL"))) {
                ADVWORD();
                if (EndWord) {
                    if(isLocAdjacent(peta,pemain,'B')){
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
                    }else{
                        printf("BNMO tidak berada di area BOIL");
                    }
                } else {
                    valid = false;
                }
            } else if (wordEqual(currentWord, strToWord("UNDO"))) {
                ADVWORD();
                if (EndWord) {

                    /* CODE UNDO */
                    UNDO(&state,&redo,&waktuGame,&pemain.lokasi,&Delivery,&Inventory);
                    fixedDisplay(&peta,pemain);
                    
                } else {
                    valid = false;
                }
            } else if (wordEqual(currentWord, strToWord("REDO"))) {
                ADVWORD();
                if (EndWord) {

                    /* CODE REDO */
                    REDO(&state,&redo,&waktuGame,&pemain.lokasi,&Delivery,&Inventory);
                    fixedDisplay(&peta,pemain);
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

                            /*Menampilkan notifikasi bahwa pembelian berhasil */
                            notifikasiPembelian(temp);

                            /*Menambahkan makanan ke delivery list */
                            Enqueue(&Delivery,temp);
                            command = true;
                        }
                    }else{
                        printf("BNMO tidak berada di area telepon!");
                    }
                } else {
                    valid = false;
                }
            } else if(wordEqual(currentWord, strToWord("INVENTORY"))){
                ADVWORD();
                if(EndWord){
                    PrintPrioQueue(Inventory);
                }
            }else if (wordEqual(currentWord, strToWord("DELIVERY"))) {
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

                            /* CODE MOVE (Arah disimpen di moveDirection) */
                            if (moveDirection.TabWord[0] == 'N') {
                                moveNorth(&peta, &pemain, &command);
                            } else if (moveDirection.TabWord[0] == 'S') {
                                moveSouth(&peta, &pemain, &command);
                            } else if (moveDirection.TabWord[0] == 'W') {
                                moveWest(&peta, &pemain, &command);
                            } else if (moveDirection.TabWord[0] == 'E') {
                                moveEast(&peta, &pemain, &command);
                            }

                        } else {
                            valid = false;
                        }
                    } else {
                        valid = false;
                    }
                }
            }else if(wordEqual(currentWord,strToWord("EXIT"))){
                started = false;
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
                                    wait = true;
                                    updateMenit = waitX * 60 + waitY;
                                    // waktuGame =  MenitToTIME( TIMEToMenit(waktuGame) + waitX*60 + waitY);
                                   
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
            finishDelivery(&Delivery,&Inventory);
            cleanKedaluarsa(&Inventory);
            states temp = {waktuGame,pemain.lokasi,Delivery,Inventory};
            PushStack(&state,temp);
        }else if(wait){
            PrioQueue temp1;
            PrioQueue temp2; 

            /*Mengcopy Delivery dan Inventory ke temp1 dan temp2*/
            copyPrioQueue(Delivery,&temp1);
            copyPrioQueue(Inventory,&temp2);

            /*Mengupdate waktu sesuai menit yang di wait*/
            updateAllQueue(&temp1,&temp2,updateMenit);

            /*Mengcopy kembali temp1 ke delivery dan temp2 ke inventory*/
            copyPrioQueue(temp1,&Delivery);
            copyPrioQueue(temp2,&Inventory);

            /* Menambahkan N menit waktu ke dalam waktu game */
            NextNMenit(&waktuGame,updateMenit);
            states temp = {waktuGame,pemain.lokasi,temp1,temp2};
            /* Push States ke dalam stack */
            PushStack(&state,temp);
        }
        
    }
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