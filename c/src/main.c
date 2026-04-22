#include "..\header\lut_gen.h"

int main(void)
{
	int m;

	uint8_t *mult_mat;
	uint8_t *add_mat;

	char* filename = "output.dat";
	printf("\nDimensione m dello spazio di Galois GF(2^m): ");
	scanf("%d", &m);

	mult_mat = gen_mult_form(m);
	add_mat = gen_add_form(m);
	write_to_file(filename, add_mat, mult_mat);

	return 0;
}