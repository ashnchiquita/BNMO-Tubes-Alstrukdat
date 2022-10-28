#include "../commands.h"
#include <stdio.h>

int startCommand(Word w1){
    // List Command 
    // 1. START
    // 2.EXIT
    // 3. Catalog
    // 4.BUY
    // 5.FRY 
    // 6. Boil
    // 7.Move North 
    // 8. Move South
    // 9. Move East
    // 10. Move West 
    Word Start = {"START",5};
    Word Exit = {"EXIT",4};
    Word Catalog = {"CATALOG",7};
    Word Buy = {"BUY",3};
    Word Fry = {"FRY",3};
    Word Boil = {"BOIL",4};
   

    if(wordEqual(w1,Start)){
        return 1; 
    }else if(wordEqual(w1,Exit)){
        return 2; 
    }else if(wordEqual(w1,Catalog)){
        return 3;
    }else if(wordEqual(w1,Buy)){
        return 4;
    }else if(wordEqual(w1,Fry)){
        return 5;
    }else if(wordEqual(w1,Boil)){
        return 6;
    }else{
        return 0;
    }
}