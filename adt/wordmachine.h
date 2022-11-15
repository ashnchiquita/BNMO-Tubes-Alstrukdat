/* File: wordmachine.h */
/* Definisi Word Machine: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "charmachine.h"
#include "liststatik.h"

#define NMax 50
#define BLANK ' '

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

typedef struct 
{
   Word contents[NMax];
   int Length;
} WordList;


/* State Mesin Word */
extern boolean EndWord;
extern Word currentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void STARTINPUT();

void ADVSPASI();

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void printWord(Word w);
/* Menampilkan kata ke dalam layar */
/* I.S. : word W terdfinisi*/
/* F.S : word W tercetak ke dalam layar  */

void printWordAlt(Word w);

void ADVNEWLINE();
/* Mengabaikan '\n */
/* I.S. : currentChar = MARK dan EndWord bernilai true  */
/* F.S. : currentChar != MARK dan EndWord bernilai false */

Word concatWord(Word w1, Word w2);
/* Menggabungkan dua kata menjadi 1 kata */

Word CopyPaste(Word w);
/* Mengcopy Word w menjadi Word lain */

boolean wordEqual(Word w1, Word w2);
/* Mengembalikan nilai benar (true) jika Word w1 = Word w2 */

void CopySpasi();

int wordToInt(Word w);
/* Mengembalikan nilai integer dari Word yang tersusun dari angka-angka */
/* Prekondisi: isWordInt(w) bernilai true */

boolean isWordInt(Word w);
/* Mengecek apakah suatu Word merupakan bilangan */

Word strToWord(char s[]);
/* Mengubah string menjadi Word */
/* String pasti diakhiri '\0' */
/* Prekondisi: string tidak mengandung ' ' */

boolean isEmptyWL(WordList wl);

void createWL(WordList * wl);

void appendWL(Word w, WordList * wl);

void printWL(WordList wl, char splitter[]);

WordList copyWL (WordList wl);

void untilEndWord();
/* Meng-adv current word sampai habis (untuk handling error input yang tidak valid tabrakan) */

#endif
