#include <stdio.h>
#include "../liststatik.h"

/* ********** KONSTRUKTOR ********** */
void CreateListStatik(ListStatik *l) {
	int i;
	for (i = IDX_MIN; i < CAPACITY; i++) {
		ELMT(*l, i) = -1;
	}
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
int listLength(ListStatik l) {
	int i, length;
	length = 0;
	for (i = IDX_MIN; i < CAPACITY; i++) {
		if (ELMT(l, i) != MARKList) {
			length += 1;
		}
	}
	return length;
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l) {
	int i;
	for (i = IDX_MIN; i < CAPACITY; i++) {
		if (ELMT(l, i) != MARKList) {
			return i;
		}
	}
	
}

IdxType getLastIdx(ListStatik l) {
	int i;
	for (i = CAPACITY-1; i >= IDX_MIN; i--) {
			if (ELMT(l, i) != MARKList) {
				return i;
			}
		}
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i) {
	return ((i >= IDX_MIN) && (i <= CAPACITY-1));
}


boolean isIdxEff(ListStatik l, IdxType i) {
	return ((i >= IDX_MIN) && (i <= listLength(l)-1));
}

/* ********** TEST KOSONG/PENUH ********** */
boolean isEmpty(ListStatik l) {
	return (listLength(l) == 0);
}

boolean isFull(ListStatik l) {
	return (listLength(l) == CAPACITY);
}

void readList(ListStatik *l) {
	int n, i;
	do {
		scanf("%d", &n);
	} while ((n < 0) || (n > CAPACITY));
	CreateListStatik(l);
	for (i = IDX_MIN; i < n; i++) {
		scanf("%d", &ELMT(*l, i));
	}
}

void printList(ListStatik l) {
	int i, length;
	length = listLength(l);
	printf("[");
	if (length != 0) {
		for (i = IDX_MIN; i < length-1; i++) {
		printf("%d,", ELMT(l,i));
	}
	printf("%d]", ELMT(l,length-1));
	} else {
		printf("]");
	}
}

/* ********** OPERATOR ARITMATIKA ********** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus) {
	int i, length;
	length = listLength(l1);
	if (plus) {
		for (i = IDX_MIN; i < length; i++) {
			ELMT(l1,i) += ELMT(l2,i);
		}
	} else {
		for (i = IDX_MIN; i < length; i++) {
			ELMT(l1,i) -= ELMT(l2,i);
		}
	}
	return l1;
}


/* ********** OPERATOR RELASIONAL ********** */
boolean isListEqual(ListStatik l1, ListStatik l2) {
	int i, length;
	length = listLength(l1);
	if (length == listLength(l2)) {
		for (i = 0; i < length; i++) {
			if (ELMT(l1,i) != ELMT(l2,i)) {
				return false;
			}
		}
		return true;
	} else {
		return false;
	}
}

/* ********** SEARCHING ********** */
int indexOf(ListStatik l, ElType val) {
	int i, length;
	length = listLength(l);
	for (i = IDX_MIN; i < length; i++) {
		if (ELMT(l,i) == val) {
			return i;
		}
	}
	return IDX_UNDEF;
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min) {
	int i;
	*max = ELMT(l,IDX_MIN);
	*min = ELMT(l,IDX_MIN);
	
	i = 1;
	while (ELMT(l,i) != MARKList) {
		if (ELMT(l,i) > *max) {
			*max = ELMT(l,i);
		}	
		if (ELMT(l,i) < *min) {
			*min = ELMT(l,i);
		}
		i++;
	}
}

/* ********** MENAMBAH ELEMEN ********** */
void insertFirst(ListStatik *l, ElType val) {
	int i, length;
	length = listLength(*l);
	for (i = length; i > IDX_MIN; i--) {
		ELMT(*l,i) = ELMT(*l,i-1);
	}
	ELMT(*l,IDX_MIN) = val;
}

void insertAt(ListStatik *l, ElType val, IdxType idx) {
	int i, length;
	length = listLength(*l);
	for (i = length; i > idx; i--) {
		ELMT(*l,i) = ELMT(*l,i-1);
	}
	ELMT(*l,idx) = val;
}

void insertLast(ListStatik *l, ElType val) {
	int length;
	length = listLength(*l);
	ELMT(*l,length) = val;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteFirst(ListStatik *l, ElType *val) {
	int i, length;
	*val = ELMT(*l, IDX_MIN);
	length = listLength(*l);
	for (i = IDX_MIN; i < length; i++) {
		ELMT(*l,i) = ELMT(*l,i+1);
	}
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx) {
	int i, length;
	*val = ELMT(*l, idx);
	length = listLength(*l);
	for (i = idx; i < length; i++) {
		ELMT(*l,i) = ELMT(*l,i+1);
	}
}

void deleteLast(ListStatik *l, ElType *val) {
	int i, length;
	length = listLength(*l);
	*val = ELMT(*l, length-1);
	ELMT(*l, length-1) = MARKList;
}

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc) {
	int i, j, length, temp, idx;
	length = listLength(*l);
	if (asc) {
		for (i = IDX_MIN; i < length; i++) {
			idx = i;
			for (j = i+1; j < length; j++) {
				if (ELMT(*l,j) < ELMT(*l,idx)) {
					idx = j;
				}
			}
			
			if (idx != i) {
				temp = ELMT(*l, i);
				ELMT(*l, i) = ELMT(*l, idx);
				ELMT(*l, idx) = temp;
			}
		}
	} else {
		int idx;
		for (i = IDX_MIN; i < length; i++) {
			idx = i;
			for (j = i+1; j < length; j++) {
				if (ELMT(*l,j) > ELMT(*l,idx)) {
					idx = j;
				}
			}
			
			if (idx != i) {
				temp = ELMT(*l, i);
				ELMT(*l, i) = ELMT(*l, idx);
				ELMT(*l, idx) = temp;
			}
		}
	}
}
