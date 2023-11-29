#include "tige.h"
#include <assert.h>
#include <stdlib.h>
#define STACK_SIZE 4

/* Full definition of the s_stack structure */
struct s_tige {
    int *tige;
    int top;
    int capacity;
};

Tige *createTige() {
    Tige *s;
    size_t capacity = STACK_SIZE;
    s = malloc(sizeof(struct s_tige));
    s->tige = malloc(sizeof(int) * capacity);
    s->capacity = capacity;
    s->top = -1;
    return (s);
}

void deleteStack(ptrTige *s) {
    free((*s)->tige);
    free(*s);
    *s = NULL;
}

Tige *tigePush(Tige *s, int e) {
    assert(s->top != STACK_SIZE - 1);
    s->tige[++(s->top)] = e;
    return (s);
}

bool tigeEmpty(Tige *s) { return (s->top == -1); }

Tige *tigePop(Tige *s) {
    assert(!tigeEmpty(s));
    --(s->top);
    return (s);
}

int tigeTop(Tige *s) {
    assert(!tigeEmpty(s));
    return (s->tige[s->top]);
}

bool tigeOverflow(Tige *s) { return s->top + 1 == s->capacity; }

void tigeDump(FILE *f, Tige *s, void (*dumpfunction)(FILE *f, int e)) {
    fprintf(f, "(%d) --  ", s->top + 1);
    for (int i = s->top; i >= 0; --i)
        dumpfunction(f, s->tige[i]);
}

bool compareTiges(Tige *s1, Tige *s2) {
    if (s1->top != s2->top)
        return false;
    else {
        for (int i = s1->top; i > -1; i--) {
            if (s1->tige[i] != s2->tige[i])
                return false;
        }
        return true;
    }
}

void tigeFourDump(Tige *s1, Tige *s2, Tige *s3, Tige *s4) {
    int valeur;
    for (int i = 3; i > -1; i--) {
        valeur = s1->top >= i ? s1->tige[i] : 0;
        printf("| %d ", valeur);
        valeur = s2->top >= i ? s2->tige[i] : 0;
        printf("| %d ", valeur);
        valeur = s3->top >= i ? s3->tige[i] : 0;
        printf("| %d ", valeur);
        valeur = s4->top >= i ? s4->tige[i] : 0;
        printf("| %d ", valeur);
        printf("|\n");
    }
}
