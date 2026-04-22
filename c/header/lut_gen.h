#ifndef LUT_GEN_H__
#define LUT_GEN_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

uint8_t* gen_mult_form(int);
uint8_t* gen_add_form(int);
uint8_t pol_reader(int);
uint8_t** combinator(uint8_t*, uint8_t*, int);
void write_to_file(char*, uint8_t*, uint8_t*);

#endif // LUT_GEN_H__