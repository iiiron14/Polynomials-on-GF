#include "..\header\lut_gen.h"

uint8_t* gen_mult_form(int m)
{
	int q = (int) pow(2,m);

	uint8_t* mat = (uint8_t *)malloc(sizeof(uint8_t)*q);

	mat[0] = 0;
	mat[1] = 1;
	// How to make it work if there are the element 1 and also the power 1?
	for(uint8_t i=1; i<=q-2; i++)
		mat[i+1] = i;
	return mat;
}

uint8_t* gen_add_form(int m)
{
	return NULL;
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