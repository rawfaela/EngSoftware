#include <stdio.h>
#include <locale.h>

//inverter o conteudo do penultimo com o antepenultimo

int main()
{
	setlocale(LC_ALL,"Portuguese");
	
	int tamanhoVetor, aux;
	
	printf("Digite o tamanho do vetor: ");
	scanf("%i",&tamanhoVetor);
	
	int A[tamanhoVetor];

	printf("Vetor A\n");
	for (int i = 0; i < tamanhoVetor; i++)
	{
		printf("Digite um número para adicionar ao vetor: ");
		scanf("%i",&A[i]);
	}
	
	aux = A[tamanhoVetor - 3];
	A[tamanhoVetor - 3] = A[tamanhoVetor - 2];
	A[tamanhoVetor - 2] = aux;
	
	for (int i = 0; i < tamanhoVetor; i++)
	{
		printf("A[%i]: %i\n",i,A[i]);
	}
}
