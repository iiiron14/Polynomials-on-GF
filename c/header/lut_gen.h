#ifndef LUT_GEN_H__
#define LUT_GEN_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

int* power_gen(int);
int* add_gen(int*, int, int);
int pol_reader(int);
void pol_writer(int, int);
uint8_t** combinator(uint8_t*, uint8_t*, int);
void write_to_file(char*, int*, int*, int);

void print_binary(int, int);
uint8_t is_primitive(int, int);

#endif // LUT_GEN_H__

/*
examples of primitive polynoms
Polynom: 1 + x^3 + x^4
Polynom: 1 + x^3 + x^5
*/