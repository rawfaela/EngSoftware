#include <stdio.h>
#include <locale.h>

//inverter os elementos pares e ímpares

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
	
	for (int i = 0; i < tamanhoVetor; i++)
    {
      if (i%2 == 0 && i<tamanhoVetor-1)
      {
        aux = A[i+1];
        A[i+1] = A[i];
        A[i] = aux;
      }
      printf("%i\t",A[i]);
    }
}
