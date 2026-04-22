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
void write_to_file(char*, uint8_t*, uint8_t*);

void print_binary(int, int);

#endif // LUT_GEN_H__