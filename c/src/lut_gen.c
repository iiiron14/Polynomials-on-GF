#include "..\header\lut_gen.h"

int primitive_exp(int alpha, int q);

int* power_gen(int q)
{
	int *power_mat = (int *)malloc(sizeof(int)*q);
	power_mat[0] = 0;
	for(int i=1; i<q;i++)
		power_mat[i] = 1U<<(i-1);
	return power_mat;
}

int* add_gen(int* power_mat, int m, int pol)
{
	int q = (int) pow(2,m);
	int *add_mat = (int *)malloc(sizeof(int)*q);
	int rem, exponent, rem_grade;
	add_mat[0] = 0;
	for(int i=1; i<q; i++)
	{
		exponent = primitive_exp(power_mat[i], q);
		rem = power_mat[i];
		// printf("\n\nTEST: exponent=%d", exponent);
		do
		{
			rem_grade = exponent - m;
			rem = rem ^ (pol << (rem_grade));
			exponent = primitive_exp(rem, q);
			// printf("\nrem_grade: %d, exponent: %d, rem: ", rem_grade, exponent);
			// print_binary(rem, q-1);
		}while(exponent >= m);
		add_mat[i] = rem;
	}
	return add_mat;
}

int primitive_exp(int alpha, int q)
{
	int exponent=q-1;
	while(((alpha >> exponent) & 1U) != 1U)
	{
		exponent--;
	}
	return exponent;
}

uint8_t** combinator(uint8_t *add_mat, uint8_t *mult_mat, int m)
{
	return NULL;
}

int pol_reader(int m)
{
	int pol_coeff;
	int pol=0;
	for(int i=0; i<=m; i++){
		do{
			printf("\nCoefficiente x^%d: ", i);
			scanf("%d", &pol_coeff);
		} while((pol_coeff != 0) && (pol_coeff != 1));
		pol |= (pol_coeff << i);
	}
	return pol;
}

void pol_writer(int pol, int len)
{
	printf("\nPolynom: ");
	for(int i=0; i <= len; i++)
	{
		if(!i && (pol & 1U))
			printf("1 ");
		else if((i != len) && (pol>>i & 1U))
			printf("+ x^%d ", i);
		else if((i==len) && (pol>>i & 1U))
			printf("+ x^%d", i);
	}
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