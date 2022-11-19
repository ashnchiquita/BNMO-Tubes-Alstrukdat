#include "set.h"

Tree *addToSet(Set *set, Object value) {
    return addChildren(&(set->imnRoot), value);
}

Set *getSetFromTree(Tree *tree) {
    Set *set = malloc(sizeof(Set));
    set->imnRoot = *tree;

    return set;
}