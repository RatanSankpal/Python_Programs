#include<stdio.h>

void sumproduct(int a, int b, int *sum,int *product)
{
	*sum = a+b;
        *product = a*b ;
}

int main()
{
	int a, b, sum,product;
	printf("\n Enter 2 no:");
	scanf("%d%d", &a,&b);
	
        sumproduct( a,  b, & sum, & product);

	
	
        printf("sum =%d \n",sum);
	
        printf("product =%d \n",product);

	return 0;

}