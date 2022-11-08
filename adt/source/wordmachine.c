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

void STARTINPUT(){
    START();
    IgnoreBlanks();
    if(currentChar == MARK){
        EndWord = true;
    }else{
        EndWord = false;
        CopySpasi();
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

void ADVSPASI(){
    Word EMPTY = {"", 0};
    currentWord = EMPTY;
    IgnoreBlanks();
    if(currentChar == MARK){
        EndWord = true;
    }
    else{
        CopySpasi();
        IgnoreBlanks();
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
    currentWord.Length = 0;
    while (currentChar != MARK && currentChar != BLANK)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else
            break;
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

void printWordAlt(Word w) {
    for(int i =0; i < w.Length;i++){
        printf("%c",w.TabWord[i]);    
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

void CopySpasi() {
    currentWord.Length = 0;
    while (currentChar != MARK)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else
            break;
    }
}

int wordToInt(Word w) {
/* Mengembalikan nilai integer dari Word yang tersusun dari angka-angka */
/* Prekondisi: isWordInt(w) bernilai true */
    /* KAMUS LOKAL */
    int bil, i;

    /* ALGORITMA */
    bil = 0;
    for(i = 0; i < w.Length; i++) {
        bil *= 10;
        bil += (w.TabWord[i] - 48);
    }

    return bil;
}

boolean isWordInt(Word w) {
/* Mengecek apakah suatu Word merupakan bilangan */
    /* KAMUS LOKAL */
    boolean num;
    int i;

    /* ALGORITMA */
    num = true;

    for (i = 0; i < w.Length && num; i++) {
        num = (w.TabWord[i] >= 48 && w.TabWord[i] <= 57);
    }

    if (w.Length == 0) {
        num = false;
    }

    return num;
}

Word strToWord(char s[]) {
/* Mengubah string menjadi Word */
/* String pasti diakhiri '\0' */
/* Prekondisi: string tidak mengandung ' ' */
    /* KAMUS LOKAL */
    int i;
    Word w;

    /* ALGORITMA */
    i = 0;
    while (s[i] != '\0') {
        w.TabWord[i] = s[i];
        i++;
    }

    w.Length = i;

    return w;
}

boolean isEmptyWL(WordList wl) {
    return (wl.Length == 0);
}
void createWL(WordList * wl) {
    (*wl).Length = 0;
}

void appendWL(Word w, WordList * wl) {
  (*wl).contents[(*wl).Length] = w;
  (*wl).Length++;
}

void printWL(WordList wl, char splitter[]) {
   int i;
   for (i = 0; i < wl.Length; i++) {
      printWordAlt(wl.contents[i]);
      if (i != wl.Length - 1) {
         printf("%s", splitter);
      }
   }
}

WordList copyWL (WordList wl) {
    WordList copy;
    int i;
    copy.Length = wl.Length;
    for (i = 0; i < wl.Length; i++) {
        copy.contents[i] = CopyPaste(wl.contents[i]);
    }
    return copy;
}