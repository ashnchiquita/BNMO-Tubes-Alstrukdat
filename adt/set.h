//
// Created by zidane on 11/15/22.
//

#ifndef BNMO_TUBES_ALSTRUKDAT_SET_H
#define BNMO_TUBES_ALSTRUKDAT_SET_H

#include "tree.h"

typedef struct treeSet {
    Tree imnRoot;
} Set;

Tree *addToSet(Set *set, Object value);
Set *getSetFromTree(Tree *tree);


#endif //BNMO_TUBES_ALSTRUKDAT_SET_H
