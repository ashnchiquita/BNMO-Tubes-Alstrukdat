#include "../boolean.h"
#include "../charmachine.h"
#include "../wordmachine.h"
#include <stdio.h>


boolean EndWord;
Word currentWord;

void IgnoreBlanks() {
    while (currentChar == BLANK) {
        ADV();
    }
}


void STARTWORD() {
    START();
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    }
    else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD() {
    Word EMPTY = {"", 0};
    currentWord = EMPTY;
    IgnoreBlanks();
    if(currentChar == MARK){
        EndWord = true;
    }
    else{
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord() {
    int i = 0;
    while(currentChar != MARK && currentChar != BLANK){
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    if (i > NMax){
        currentWord.Length = NMax;
    }
    else{
        currentWord.Length = i;
    }
}

boolean validateChar(char a){
    return((a>= 65 && a <=90) || (a>= 97 && a <= 122));
}

void printWord(Word w){
    for(int i =0; i < w.Length;i++){
        if(!validateChar(w.TabWord[i])){
            printf(" ");
        }else{
            printf("%c",w.TabWord[i]);
        }
        
    }
}

void ADVNEWLINE() {
    Word EMPTY = {"", 0};
    currentWord = EMPTY;
    while(currentChar == MARK){
        EndWord = false;
        ADV();
    }
}

Word concatWord(Word w1, Word w2){
    Word w3;
    w3.Length = w1.Length + w2.Length;
    for(int i =0 ; i < w1.Length;i++){
        w3.TabWord[i] = w1.TabWord[i];
    }
    int j = w1.Length;
    for(int i = 0; i < w2.Length;i++){
        w3.TabWord[j] = w2.TabWord[i];
        j++;
    }
    return w3;
}

Word CopyPaste(Word w){
    Word wResult;
    wResult.Length = w.Length;
    for(int i =0; i< wResult.Length;i++){
        wResult.TabWord[i] = w.TabWord[i];
    }
    return wResult;
}

char toLowerChar(char a){
    if(a >= 65 && a <=90){
        return a + 32;
    }else{
        return a;
    }
}

boolean wordEqual(Word w1, Word w2){
    if(w1.Length != w2.Length){
        return false;
    }else{
        for(int i =0 ; i < w1.Length;i++){
            if(toLowerChar(w1.TabWord[i]) != toLowerChar(w2.TabWord[i])){
                return false;
            }
        }
        return true;
    }
}