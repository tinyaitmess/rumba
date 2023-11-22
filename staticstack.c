/*-----------------------------------------------------------------*/
/*
 Licence Informatique - Structures de données
 Mathias Paulin (Mathias.Paulin@irit.fr)

 Implantation du TAD Stack étudié en cours.

 */
/*-----------------------------------------------------------------*/
#include "stack.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 3

/* Full definition of the s_stack structure */
struct s_stack {
    int **stack; // array of void *
    int top;
    int capacity;
};

Stack *createStack() {
    Stack *s;
    size_t capacity = STACK_SIZE;
    s = malloc(sizeof(struct s_stack));
    s->stack = malloc(sizeof(void *) * capacity);
    s->capacity = capacity;
    s->top = -1;
    return (s);
}

void deleteStack(ptrStack *s) {
    free((*s)->stack);
    free(*s);
    *s = NULL;
}

Stack *stackPush(Stack *s, void *e) {
    assert(s->top != STACK_SIZE - 1);
    s->stack[++(s->top)] = e;
    return (s);
}

bool stackEmpty(Stack *s) { return (s->top == -1); }

Stack *stackPop(Stack *s) {
    assert(!stackEmpty(s));
    --(s->top);
    return (s);
}

int *stackTop(Stack *s) {
    assert(!stackEmpty(s));
    return (s->stack[s->top]);
}

bool stackOverflow(Stack *s) { return s->top + 1 == s->capacity; }

void stackDump(FILE *f, Stack *s, void (*dumpfunction)(FILE *f, int *e)) {
    fprintf(f, "(%d) --  ", s->top + 1);
    for (int i = s->top; i >= 0; --i)
        dumpfunction(f, s->stack[i]);
}

void stackFourDump(Stack *s1, Stack *s2, Stack *s3, Stack *s4) {
    int valeur;
    for (int i = 3; i > -1; i--) {
        valeur = s1->top >= i ? *s1->stack[i] : 0;
        printf("| %d ", valeur);
        valeur = s2->top >= i ? *s2->stack[i] : 0;
        printf("| %d ", valeur);
        valeur = s3->top >= i ? *s3->stack[i] : 0;
        printf("| %d ", valeur);
        valeur = s4->top >= i ? *s4->stack[i] : 0;
        printf("| %d ", valeur);
        printf("|\n");
    }
}

bool compareStack(Stack *s1, Stack *s2) {
    if (s1->top != s2->top)
        return false;
    else {
        for (int i = s1->top; i > -1; i--) {
            if (s1->stack[i] != s2->stack[i])
                return false;
        }
        return true;
    }
}
