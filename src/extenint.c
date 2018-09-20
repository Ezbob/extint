#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "extenint.h"

static int extint_extend(extint_t **, size_t);

extint_t *extint_new() {

    size_t size = offsetof(extint_t, num) + 1 * sizeof(uint64_t);
    extint_t *new = malloc(size);
    if (new == NULL) {
        return NULL;
    }
    new->length = 1;
    new->num[0] = 0;
    return new;
}

void extint_del(extint_t *eint) {
    free(eint);
}

static int extint_extend(extint_t **eint, size_t numadd) {

    size_t oldlen = (*eint)->length;
    size_t newlen = oldlen + numadd;
    size_t newsize = offsetof(extint_t, num) + newlen * sizeof(uint64_t);

    extint_t *neweint = realloc(*eint, newsize);
    if ( neweint == NULL ) {
        return 0;
    }
    neweint->length = newlen;
    for ( size_t i = oldlen; i < newlen; ++i ) {
        neweint->num[i] = 0;
    }

    *eint = neweint;
    return 1;
}


int main(void) {

    extint_t *a = extint_new();

    printf("%lu \n", sizeof(a));
    printf("%lu \n", a->num[0]);

    a->num[0] = 10;

    printf("%lu \n", a->num[0]);
    extint_extend(&a, 2);

    for (ssize_t i = 0; i < a->length; ++i) {
        printf("%lu ", a->num[i]);
    }

    extint_del(a);
    return 0;
}
