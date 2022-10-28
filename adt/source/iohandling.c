#include <stdio.h>
#include "../boolean.h"
#include "../iohandling.h"
#include "../wordmachine.h"

/* Word Operations */
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

boolean isWordEq(Word w1, Word w2) {
/* Mengecek apakah w1 == w2 */
    /* KAMUS LOKAL */
    boolean eq;
    int i;

    /* ALGORITMA */
    eq = true;

    if (w1.Length == w2.Length) {
        for (i = 0; i < w2.Length && eq; i++) {
            eq = w1.TabWord[i] == w2.TabWord[i];
        }
    } else {
        eq = false;
    }

    return eq;
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

Word duplicateWord(Word w) {
/* Mengembalikan salinan dari w */
    /* KAMUS LOKAL */
    int i;
    Word wHasil;

    /* ALGORITMA */
    wHasil.Length = w.Length;
    for (i = 0; i < w.Length; i++) {
		wHasil.TabWord[i] = w.TabWord[i];
	}

    return wHasil;
}

void printWord(Word w) {
/* I.S. w terdefinisi */
/* F.S. Menampilkan Word w, tanpa karakter tambahan apapun di ujungnya */
    /* KAMUS LOKAL */
    int i;

    /* ALGORITMA */
	for (i = 0; i < w.Length; i++) {
		printf("%c", w.TabWord[i]);
	}
}

/* Sentence Operations */
boolean isEmptySentence(Sentence s) {
/* Mengecek apakah sentence s kosong atau tidak */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    return s.Length == 0;
}
void createSentence(Sentence *s) {
/* I.S. s sembarang */ 
/* F.S. Membuat sebuah Sentence kosong */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    (*s).Length = 0;
}

Sentence takeInput() {
/* Mengambil input kalimat dari pengguna dan mengembalikan Sentence yang mewakili kalimat masukan pengguna */
    /* KAMUS LOKAL */
    Sentence s;

    /* ALGORITMA */
    s.Length = 0;
    STARTWORD();
    
    while (!EndWord) {
        appendSentence(&s, currentWord);
        ADVWORD();
    }
    
    return s;
}

Sentence strToSentence(char s[]) {
/* Mengembalikan sebuah Sentence yang mewakili string s (kerjanya seperti mesin kata) */
    /* KAMUS LOKAL */
    Sentence hasil;
    Word tempW;
    int i, j;

    /* ALGORITMA */
    i = 0;
    j = 0;
    tempW.Length = 0;
    createSentence(&hasil);

    while (s[i] != '\0') {
        if (s[i] == ' ') {
            if (tempW.Length != 0) {
                appendSentence(&hasil, tempW);
            }

            j = 0;
            tempW.Length = 0;

        } else {
            tempW.Length++;
            tempW.TabWord[j] = s[i];
            j++;
        }
        i++;
    }

    if (tempW.Length != 0) {
        appendSentence(&hasil, tempW);
    }

    return hasil;
}

boolean isSentenceEq(Sentence s1, Sentence s2) {
/* Mengecek apakah s1 == s2 */
    /* KAMUS LOKAL */
    boolean eq;
    int i;

    /* ALGORITMA */
    eq = true;

    if (s1.Length == s2.Length) {
        for (i = 0; i < s2.Length && eq; i++) {
            eq = isWordEq(s1.T[i], s2.T[i]);
        }
    } else {
        eq = false;
    }

    return eq;
}

void appendSentence(Sentence * s, Word w) {
/* I.S. s dan w terdefinisi, s bisa kosong */
/* F.S. w ditambahkan ke s */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    (*s).T[(*s).Length] = duplicateWord(w);
    (*s).Length++;
}

void printSentence(Sentence s) {
/* I.S. s terdefinisi */
/* F.S. Menampilkan isi Sentence s, tanpa karakter tambahan apapun di ujungnya */
    /* KAMUS LOKAL */
    int i;

    /* ALGORITMA */
    if (s.Length != 0) {
        printWord(s.T[0]);
        
        for (i = 1; i < s.Length; i++) {
            printf(" ");
            printWord(s.T[i]);
        }
    }
}