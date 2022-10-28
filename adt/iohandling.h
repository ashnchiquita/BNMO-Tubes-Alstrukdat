#ifndef IO_HANDLING_H
#define IO_HANDLING_H

#include "boolean.h"
#include "wordmachine.h"

#define MaxWord 30

/* Tempat menyimpan masukan pengguna (string) */
typedef struct {
    Word T[MaxWord];
    int Length;
} Sentence;

/* Word Operations */
boolean isWordInt(Word w);
/* Mengecek apakah suatu Word merupakan bilangan */

boolean isWordEq(Word w1, Word w2);
/* Mengecek apakah w1 == w2 */

int wordToInt(Word w);
/* Mengembalikan nilai integer dari Word yang tersusun dari angka-angka */
/* Prekondisi: isWordInt(w) bernilai true */

Word strToWord(char s[]);
/* Mengubah string menjadi Word */
/* String pasti diakhiri '\0' */
/* Prekondisi: string tidak mengandung ' ' */

Word duplicateWord(Word w);
/* Mengembalikan salinan dari w */

void printWord(Word w);
/* I.S. w terdefinisi */
/* F.S. Menampilkan Word w, tanpa karakter tambahan apapun di ujungnya */


/* Sentence Operations */
boolean isEmptySentence(Sentence s);
/* Mengecek apakah sentence s kosong atau tidak */

void createSentence(Sentence *s);
/* I.S. s sembarang */ 
/* F.S. Membuat sebuah Sentence kosong */

Sentence takeInput();
/* Mengambil input kalimat dari pengguna dan mengembalikan Sentence yang mewakili kalimat masukan pengguna */

Sentence strToSentence(char s[]);
/* Mengembalikan sebuah Sentence yang mewakili string s (kerjanya seperti mesin kata) */

boolean isSentenceEq(Sentence s1, Sentence s2);
/* Mengecek apakah s1 == s2 */

void appendSentence(Sentence * s, Word w);
/* I.S. s dan w terdefinisi, s bisa kosong */
/* F.S. w ditambahkan ke s */

void printSentence(Sentence s);
/* I.S. s terdefinisi */
/* F.S. Menampilkan isi Sentence s, tanpa karakter tambahan apapun di ujungnya */

#endif