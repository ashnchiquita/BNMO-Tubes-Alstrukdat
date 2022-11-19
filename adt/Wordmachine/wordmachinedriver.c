#include"wordmachine.h"
#include <stdio.h>

int main()
{
    /* KAMUS */
    Word wStart, wExit, wMix, wChop, wFry, wBoil, wCopy;
    char strStart[5] = "START";
    char strExit[5] = "EXIT";
    char strMix[3] = "MIX";
    char strChop[4] = "CHOP";
    char strFry[3] = "FRY";
    char strBoil[4] = "BOIL";
    int val;

    /* ALGORITMA */

    // TES 1: Membaca COMMAND dan cetak sesuatu sesuai command
    /*
    START: Hello, Welcome to Anything!
    EXIT: Goodbye...
    MIX: Mixing ingredients...
    CHOP: Chopping ingredients...
    FRY: Frying ingredients...
    BOIL: Boiling ingredients...

    command TIDAK case sensitive
    */

    wStart = strToWord(strStart[5]);
    wExit = strToWord(strExit[5]);
    wMix = strToWord(strMix[3]);
    wChop = strToWord(strChop[4]);
    wFry = strToWord(strFry[3]);
    wBoil = strToWord(strBoil[4]);

    STARTWORD();
    while (!EndWord)
    {

        wCopy = currentWord;
        printf("Your command is: ");
      
        printWord(wCopy);
        printf("\n");
        if (wordEqual(currentWord, wStart))
        {
            printf("Hello, Welcome to Anything!");
        }
        else if (wordEqual(currentWord, wExit))
        {
            printf("Goodbye...");
        }
        else if (wordEqual(currentWord, wMix))
        {
            printf("Mixing ingredients...");
        }
        else if (wordEqual(currentWord, wChop))
        {
            printf("Chopping ingredients...");
        }
        else if (wordEqual(currentWord, wFry))
        {
            printf("Frying ingredients...");
        }
        else if (wordEqual(currentWord, wBoil))
        {
            printf("Boiling ingredients...");
        }
        printf("\n");
        ADVWORD();
    }

    // TES 2: Mengubah Word menjadi integer
    printf("Masukkan bilangan positif atau 0: \n");
    STARTWORD();
    while (!EndWord)
    {
        val = wordToInt(currentWord);
        if (val == -1)
        {
            printf("Bukan bilangan positif atau 0!");
        }
        else
        {
            printf("2 kali bilangan tersebut adalah: %d", val * 2);
        }

        ADVWORD();
    }

    untilEndWord();

    // TES 3: Concat 2 Word
    printf("\n\n");
    printWord(concatWord(wBoil, wChop));
    printf("\n");
    return 0;
}