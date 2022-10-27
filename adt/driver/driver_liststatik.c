#include "liststatik.h"
#include "liststatik.c"
#include <stdio.h>

int main() {
  ListStatik l1;
  ListStatik l2;
  readList(&l1);

  printf("L1: ");
  printList(l1);
  printf("\n");
  readList(&l2);
  printf("L2: ");
  printList(l2);
  printf("\n");
  printf("L1: ");
  printList(l1);
  printf("\n");
  printf("Length: %d\n", listLength(l1));
  printf("Index of 3: %d\n", indexOf(l1, 3));
  printf("isIDXVALID101: %d\n", isIdxValid(l1, 101));
  printf("isIDXVALID99: %d\n", isIdxValid(l1, 99));
  printf("isIDXEff2: %d\n", isIdxEff(l1, 2));
  printf("isEmpty: %d\n", isEmpty(l1));
  printf("isFull: %d\n", isFull(l1));
  printf("isListEqual: %d\n", isListEqual(l1, l2));
  ListStatik l3;
  l3 = plusMinusList(l1, l2, true);
  printf("L3: ");
  printList(l3);
  int max;
  int min;
  extremeValues(l3, &max, &min);
  printf("\nL3 Max: %d \nL3 MIN: %d\n", max, min);
  sortList(&l3, true);
  printf("L3 ascending: ");
  printList(l3);
  printf("L3 descending: ");
  sortList(&l3, false);
  printList(l3);
  insertLast(&l3, 69);
  printf("L3: ");
  printList(l3);
  int pop;
  deleteLast(&l3, &pop);
  printf("Pop: %d\n", pop);
  deleteLast(&l3, &pop);
  printf("Pop: %d\n", pop);
  printf("L3: ");
  printList(l3);
  return 0;
}
