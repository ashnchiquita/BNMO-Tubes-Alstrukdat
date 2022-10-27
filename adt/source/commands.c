#include "../commands.h"
#include <stdio.h>

int startCommand(Word w1){
    // List Command 
    // 1. START
    // 2.EXIT
    // 4.BUY
    // 5.FRY 
    // 6. 
    Word Start = {"START",5};
    Word Exit = {"EXIT",4};
    Word Catalog = {"CATALOG",7};
    if(wordEqual(w1,Start)){
        return 1; 
    }else if(wordEqual(w1,Exit)){
        return 2; 
    }else if(wordEqual(w1,Catalog)){
        return 3;
    }else{
        return 0;
    }
}