#include "charmachine.h"
#include <stdio.h>

int main() {
    char testFile[60] = "../../../pitakar.txt";
    /* read char from file*/
    STARTFILE(testFile);


    // print char
    while (!EOP) {
        printf("%c", currentChar);
        ADV();
    }
    printf(".\n");
    return 0;
}