
#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int item;
    struct tree * parent;
    struct tree * left;
    struct tree * right;
} tree;

tree * search_tree(tree * l, int item){
    // I am returning struct tree because skiena is doing it
    // but for this case, returning int would work
    if (l == NULL) return NULL;

    if (l->item == item) return l;

    if (item < l->item){
        // if item is lower than curr tree node
        return ( search_tree(l->left, item) );
    } else {
        return ( search_tree(l->right, item) );
    }
}

tree * find_minimum(tree * t){
    tree * min;

    if (t == NULL) return NULL;

    min = t;
    while (min->left != NULL){
        min = min->left;
    }
    return min;
}

/*
** Tree Traversal follows the following following pseudocode pattern
**
** void traverse(tree * l)
**     if l != NULL:
**         traverse(l->left)
**         process_item(l->item)
**         traverse(l->right)
*/

int main(){

    return 0;
}
