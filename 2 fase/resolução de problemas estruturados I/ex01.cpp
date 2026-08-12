#include<stdio.h>

main()
{
	int posicoes, i, aux;
	printf("Informe quantas posicoes no vetor: ");
	scanf("%i",&posicoes);
	
	int A[posicoes];
	
	printf("Vetor A\n");
	for (i = 0; i<posicoes; i++)
	{
		printf("Informe um numero: ");
		scanf("%i",&A[i]);
	}
	
	aux = A[posicoes - 3];
	A[posicoes - 3] = A[posicoes - 2];
	A[posicoes - 2] = aux;
	
	for (i=0;i<posicoes;i++)
	{
		printf("%i\t",A[i]);
	}
}
