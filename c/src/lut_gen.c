#include "..\header\lut_gen.h"

uint8_t* gen_mult_form(int q)
{
	return NULL;
}

uint8_t* gen_add_form(int q)
{
	uint8_t *mat = (uint8_t *)malloc(sizeof(uint8_t)*q);
	for(int i=0; i<q; i++)
		mat[i] = i;
	return mat;
}

uint8_t** combinator(uint8_t *add_mat, uint8_t *mult_mat, int m)
{
	return NULL;
}

uint8_t pol_reader(int m)
{
	return 0;
}

void write_to_file(char* filename, uint8_t* add_mat, uint8_t* mult_mat)
{
	return;
}

void print_binary(int n, int size)
{
	for(int i=size-1; i>=0; i--)
		printf("%d", n>>i & 1U);
}