// Implementation of functioms in Set ADT

#include <stdio.h>
#include <stdlib.h>
#include "Set.h"


typedef struct _set {
    struct node *front;
    int size;
}set;

typedef struct node {
    struct node *next;
    int data;
}node;
// Define an `item` type.  `Set` manipulates `item`s.
// typedef int item;

// Create a new `Set`.
Set newSet(void) {
    Set s = malloc(sizeof *s);
    if (s == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    s->front = NULL;
    s->size = 0;
    return s;
}
// Release all resources associated with a `Set`.
void destroySet(Set s) {
    if (s->size != 0) {
        struct node *n = s->front;
        struct node *tmp;
        while (n != NULL) {
            tmp = n->next;
            free(n);
            n = tmp;
        } 
    }
    free(s);
}

// Add an `item` to the `Set`.
void setAdd(Set s, item item) {
    if (!setContains(s, item)) {
        struct node *n = malloc(sizeof *n);
        n->data = item;
        n->next = s->front;
        s->front = n;
        s->size = s->size + 1;
    } 
}

// Remove an `item` from the `Set`.
void setRemove(Set s, item item) {
    if (setContains(s, item)) {
        struct node *curr = s->front;        
        if (curr->data == item) {
            s->front = curr->next;
            free(curr); 
            s->size = s->size - 1;
        }
        else {
            struct node *prev;
            while (curr->data != item) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            free(curr);
            s->size = s->size - 1;
        }
    }
}

// Does the `Set` contain this `item`?
bool setContains(Set s, item item) {
    struct node *n = s->front;
    while (n != NULL) {
        if (n->data == item) {
            return true;
        }
        n = n->next;
    }
 
    return false;
}
    
// How many items are in the `Set`?
int setSize(Set s) {

    return s->size;
}

// Take the union of two sets(a âˆª b).
Set setUnion(Set a, Set b) {
    Set s = newSet();
    
    for (struct node *n = a->front; n != NULL; n = n->next) {
        setAdd(s, n->data);
    }
    
    for (struct node *n = b->front; n != NULL; n = n->next) {
        setAdd(s, n->data);
    }
    return s;    
}    
// Take the intersection of two sets(a âˆ© b).
Set setIntersection(Set a, Set b) {
    Set s = newSet();
    
    for (struct node *n = a->front; n != NULL; n = n->next) {
        if (setContains(b, n->data)) {
            setAdd(s, n->data);
        }
    }
    return s;
}

// Is `a` a subset of `b`(a âŠ† b)?
bool setSubset(Set a, Set b) {
    struct node *n = a->front;
    while (n != NULL) {
        if (setContains(b, n->data) == false) {
            return false;
        }
        n = n->next;
    }
    return true;
}

// Is `a` equal to `b`(where a âŠ† b and b âŠ† a, a == b).
bool setEqual(Set a, Set b) {

    return (setSubset(a, b) && setSubset(b, a));
}

