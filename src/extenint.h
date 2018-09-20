
#ifndef EXTENINT_H_
#define EXTENINT_H_

#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

typedef struct extint_t {
    ssize_t length;
    uint64_t num[1];
} extint_t;

extint_t *extint_new();
void extint_del(extint_t *);

/*
 * Create from string 
 */
extint_t *extint_from_str(char *);
char *extint_to_str(extint_t *);

/*
 * Basic math operators. Returns a new extint with the result 
 */
extint_t *extint_add(const extint_t *, const extint_t *);
extint_t *extint_sub(const extint_t *, const extint_t *);
extint_t *extint_mul(const extint_t *, const extint_t *);
extint_t *extint_div(const extint_t *, const extint_t *);

#endif

