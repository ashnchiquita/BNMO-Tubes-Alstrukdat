#include "set.h"

Tree *addToSet(Set *set, Object value) {
    // search if a value exists in set
    int setLength = set->imnRoot.childrenCount, i = 0;
    boolean found = false;

    while (found == false && i < setLength) {
        if (set->imnRoot.children[i]->value.makananV.id == value.makananV.id) {
            found = true;
        }

        ++i;
    }

    // add if the value doesnt exist

    if (found == true) {
        return NULL;
    }

    return addChildren(&(set->imnRoot), value);

}

Set *getSetFromTree(Tree *tree) {
    Set *set = malloc(sizeof(Set));
    set->imnRoot = *tree;

    return set;
}