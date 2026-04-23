#include "..\header\lut_gen.h"

int main(void)
{
	int m, q;

	int *mult_mat;
	int *add_mat;

	int pol;

	char* filename = "output.dat";
	printf("\nDimensione m dello spazio di Galois GF(2^m): ");
	scanf("%d", &m);
	q = (int) pow(2, m);

	// POLYNOM TEST
	pol = pol_reader(m);
	pol_writer(pol, m);
	printf("\npol=%d", pol);

	// POWER MATRIX TEST
	printf("\nPower matrix");
	mult_mat = power_gen(q);
	for(int i=0; i< q; i++)
	{
		printf("\n");
		print_binary(mult_mat[i], q-1);
	}

	// ADDITION MATRIX TEST
	printf("\nAddition matrix");
	add_mat = add_gen(mult_mat, m, pol);
	for(int i=0; i< q; i++)
	{
		printf("\n");
		print_binary(add_mat[i], m);
	}

	// TEST PRIMITIVE POLYNOMIALS
	char primitive = is_primitive(pol, m) ? 'y' : 'n';
	printf("\n Primitiveness: %c", primitive);

	// TEST WRITE TO FILE
	write_to_file(filename, add_mat, mult_mat, m);
	
	free(mult_mat);
	free(add_mat);
	return 0;
}