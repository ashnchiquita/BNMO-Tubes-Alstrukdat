#include <stdio.h>
#include "liststatik.h"

void CreateListStatik(ListStatik *l) {
    int i;
    for (i = 0; i < CAPACITY; i++) {
        ELMT(*l, i) = MARK;
    }
}

int listLength(ListStatik l) {
    int i =0;
    while ((i < CAPACITY) && (ELMT(l,i) != MARK)) {
        i += 1;
    }
    return i;
}

IdxType getFirstIdx(ListStatik l) {
    int i = 0;
    return ELMT(l, i);
}
IdxType getLastIdx(ListStatik l) {
    int i = CAPACITY - 1;
    return ELMT(l, i);
}

boolean isIdxValid(ListStatik l, IdxType i) {
    return (i < CAPACITY) && (i >= 0);
}

boolean isIdxEff(ListStatik l, IdxType i) {
    return (i < listLength(l)) && (i >= 0);
}

boolean isEmpty(ListStatik l) {
    return (listLength(l) == 0);
}

boolean isFull(ListStatik l) {
    return (listLength(l) == CAPACITY);
}

void readList(ListStatik *l) {
    int n = IDX_UNDEF, i;
    CreateListStatik(l);
    while ((n > CAPACITY) || (n < 0)) {
        scanf("%d", &n);
    }
    for (i = 0; i < n; i++) {
        scanf("%d", &ELMT(*l, i));
    }
}

void printList(ListStatik l) {
    int i;
    printf("[");
    if (listLength(l) != 0) {
        printf("%d", ELMT(l,0));
        for (i =1; i < listLength(l); i++) {
            printf(",%d", ELMT(l,i));
        }
    }
    printf("]");
}

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus) {
    int i;
    ListStatik l;
    CreateListStatik(&l);
    if (plus) {
        for (i = 0; i < listLength(l1); i++) {
            ELMT(l,i) = ELMT(l1,i) + ELMT(l2,i);
        }
    }
    else {
        for (i = 0; i < listLength(l1); i++) {
            ELMT(l,i) = ELMT(l1,i) - ELMT(l2,i);
        }
    }
    return l;
}

boolean isListEqual(ListStatik l1, ListStatik l2) {
    boolean x = true;
    int i;
    if (listLength(l1) == listLength(l2)) {
        for (i = 0; i < listLength(l1); i++) {
            if (ELMT(l1,i) != ELMT(l2,i)) {
                x = false;
            }
        }
    } else {
        x = false;
    }
    return x;
}

int indexOf(ListStatik l, ElType val) {
    int i = 0;
    while ((ELMT(l,i) != val) && (i < listLength(l))) {
        i += 1;
    }
    if (ELMT(l,i) == val) {
        return i;
    } else {
        return IDX_UNDEF;
    }
}

void extremeValues(ListStatik l, ElType *max, ElType *min) {
    int i;
    *max = ELMT(l, 0);
    *min = ELMT(l, 0);
    for (i = 1; i < listLength(l); i++) {
        if (ELMT(l,i) > *max) {
            *max = ELMT(l, i);
        }
        if (ELMT(l,i) < *min) {
            *min = ELMT(l,i);
        }
    }
}

void insertFirst(ListStatik *l, ElType val) {
    ELMT(*l, listLength(*l)) = val;
}

void insertAt(ListStatik *l, ElType val, IdxType idx) {
    ELMT(*l, listLength(*l)-idx) = val;
}

void insertLast(ListStatik *l, ElType val) {
    ELMT(*l, listLength(*l)) = val;
}

void deleteFirst(ListStatik *l, ElType *val) {
    *val = ELMT(*l, listLength(*l)-1);
    ELMT(*l, listLength(*l)-1) = IDX_MIN;
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx) {
    *val = ELMT(*l, listLength(*l)-idx);
    ELMT(*l, listLength(*l)-idx) = MARK;
}

void deleteLast(ListStatik *l, ElType *val) {
    *val = ELMT(*l, listLength(*l)-1);
    ELMT(*l, listLength(*l)-1) = MARK;
}

void sortList(ListStatik *l, boolean asc) {
    ElType Temp;
    int Pass, i, IMax, IMin;
    if (asc) {
        if (listLength(*l) > 0) {
            for (Pass = 0; Pass < listLength(*l)-1; Pass++) {
                IMin = Pass;
                for (i=Pass+1; i<listLength(*l);i++) {
                    if (ELMT(*l, IMin) > ELMT(*l,1)) {
                        IMin = i;
                    }
                }
                Temp = ELMT(*l, IMin);
                ELMT(*l, IMin) = ELMT(*l, Pass);
                ELMT(*l, Pass) = Temp;
            }
        }
    } else {
        if (listLength(*l)>0) {
            for (Pass=0; Pass<listLength(*l)-1;Pass++) {
                IMax = Pass;
                for (i=Pass+1; i<listLength(*l);i++) {
                    if (ELMT(*l, IMax) < ELMT(*l,i)) {
                        IMax = i;
                    }
                }
                Temp = ELMT(*l, IMax);
                ELMT(*l, IMax) = ELMT(*l, Pass);
                ELMT(*l, Pass) = Temp;
            }
        }
    }
}
