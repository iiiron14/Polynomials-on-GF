#include "..\header\lut_gen.h"

int primitive_exp(int alpha, int q);
int pol_division(int pol, int dividend, int m);

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
	add_mat[0] = 0;
	for(int i=1; i<q; i++)
		add_mat[i] = pol_division(pol, power_mat[i], m);
	return add_mat;
}

int pol_division(int pol, int dividend, int m)
{
	int q = (int) pow(2,m);
	int rem_grade = primitive_exp(dividend, q);
	int rem = dividend;
	while(rem_grade >= m)
	{
		rem ^= (pol << (rem_grade - m));
		rem_grade = primitive_exp(rem, q);
	}
	return rem;
}

int primitive_exp(int alpha, int q)
{
	int exponent=q-1;
	if(alpha==0)
		return 0;
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
			if((i==m) && (pol_coeff==0)){
				printf("\nERRORE: il coefficiente di grado m deve essere non nullo");
				pol_coeff = -1;
			}
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

void write_to_file(char* filename, int* add_mat, int* mult_mat, int m)
{
	FILE* f;
	int q = (int) pow(2,m);
	if((f = fopen(filename, "w")) == NULL)
		exit(1);
	for(int i=0; i<q; i++)
		fprintf(f, "%d\t%d\n", mult_mat[i], add_mat[i]);
	fclose(f);
}

// Prints n in binary format of size length. Goes from MSb to LSb
void print_binary(int n, int size)
{
	for(int i=size-1; i>=0; i--)
		printf("%d", n>>i & 1U);
}


uint8_t is_primitive(int pol, int m)
{
	int q = (int) pow(2,m);
	uint8_t is_max_grade = 0;
	int dividend, rem;

	for(int i=q-1; i>0; i--)
	{
		dividend = 1;
		dividend |= (1U<<i);
		rem = pol_division(pol, dividend, m);
		if((i == q-1) && (rem==0))
			is_max_grade = 1;
		else if(rem == 0)
			is_max_grade = 0;
	}
	return is_max_grade;
}