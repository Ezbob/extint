
#ifndef EXTENINT_H_
#define EXTENINT_H_

#include <stdlib.h>

typedef struct extint_t {
    size_t length;
    long long int num[1];
} extint_t;

extint_t *new_extint();
void del_extint();

/*
 * Create from string 
 */
extint_t *extint_from_str(char *);

/*
 * Basic math operators. Returns a new extint with the result 
 */
extint_t *extint_add(const extint_t *, const extint_t *);
extint_t *extint_sub(const extint_t *, const extint_t *);
extint_t *extint_mul(const extint_t *, const extint_t *);
extint_t *extint_div(const extint_t *, const extint_t *);

#endif

