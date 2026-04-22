#include "..\header\lut_gen.h"

int main(void)
{
	int m, q;

	uint8_t *mult_mat;
	uint8_t *add_mat;

	char* filename = "output.dat";
	printf("\nDimensione m dello spazio di Galois GF(2^m): ");
	scanf("%d", &m);
	q = (int) pow(2, m);

	// MULTIPLICATION MATRIX TEST
	printf("\nMULTIPLICATION MATRIX TEST");
	mult_mat = gen_mult_form(q);
	for(int i=0; i<q-2; i++)
		printf("\n%d", mult_mat[i]);
	// ADDITION MATRIX TEST
	printf("\nADDITION MATRIX TEST");
	add_mat = gen_add_form(q);
	for(int i=0; i<q; i++){
		printf("\n");
		print_binary(add_mat[i], m);
	}
	return 0;
}