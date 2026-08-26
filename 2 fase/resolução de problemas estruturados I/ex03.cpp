#include <stdio.h>
#include <locale.h>

//ordenar

int main()
{
	setlocale(LC_ALL,"Portuguese");
	int A[5], maior = 0, cont = 5, posicao;

	for (int i = 0; i < 5; i++)
	{
		printf("Digite um número para adicionar ao vetor: ");
		scanf("%i",&A[i]);
	}
	
	while(cont!=0)
	{
		maior = 0;
		for (int i = 0; i < cont; i++)
		{
			if (A[i] > maior)
			{
				maior = A[i];
				posicao = i;
			}
		}
		cont--;
		A[posicao] = A[cont];
		A[cont] = maior;
	}
	
	
	for (int i = 0; i < 5; i++)
	{
		printf("A[%i]: %i\n",i,A[i]);
	}
}
