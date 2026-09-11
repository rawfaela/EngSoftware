/*
Uma empresa possui 10 funcionários, cada funcionário possui uma idade, tempo de empresa, sexo, setor onde trabalha e salário.
Fazer um programa que leia estas informações e imprima:
1 - Quantidade de funcionários por sexo ("M" ou "F").
2 - Nome do funcionário mais novo e do mais velho.
3 - Media idade por setor.
4 - Lista dos funcionários por ordem crescente de salário (não mostrar salário, somente nome e idade)
5 - Lista de funcionários por sexo em ordem decrescente de idade.

O programa deverá mostrar um menu de opções:
0 - Sair
1 - Informar dados dos funcionários
2 - Relatórios
	2.1 - Quantidade de funcionários por sexo.
	2.2 - Funcionário mais novo e mais velho.
	2.3 - Média de idade por setor.
	2.4 - Funcionários por ordem crescente de salário.
	2.5 - Funcionários por sexo em ordem decrescente de idade.
	2.6 - Retornar ao menu anterior.
*/

#include <stdio.h>
#include <locale.h>
#include <ctype.h>

struct Funcionario //aprendi no curso tecnico
{
	char nome[50], setor[50], sexo;
	int idade;
	float tempo, salario;
};

int main()
{
	setlocale(LC_ALL,"Portuguese");
	
	Funcionario funcionarios[10], maiorFunc;
	
	int op, opR, contM, contF, qtd = 0, maior, menor, maiorSal, posSal, contPos;
	
	for (int i = 0; i<10; i++)
	{
		printf("\n==== MENU ====\n");
		printf("0- Sair\n1- Informar dados dos funcionários\n2- Relatórios\nDigite sua opção: ");
		scanf("%i",&op);
		
		switch (op)
		{
			case 0:
				printf("\nSaindo!\n");
				break;
			break;
			
			case 1:
				printf("Digite o nome do funcionário: ");
				scanf(" %[^\n]", funcionarios[i].nome);
				
				printf("Digite a idade do funcionário: ");
				scanf("%i",&funcionarios[i].idade);
				
				printf("Digite o tempo de empresa do funcionário: ");
				scanf("%f",&funcionarios[i].tempo);
				
				do 
				{
					printf("Digite o sexo do funcionário (M/F): ");
					scanf(" %c",&funcionarios[i].sexo);
					funcionarios[i].sexo = toupper(funcionarios[i].sexo);
					if (funcionarios[i].sexo != 'M' && funcionarios[i].sexo != 'F')
					{
						printf("Sexo inválido.\n");
					}
				} while (funcionarios[i].sexo != 'M' && funcionarios[i].sexo != 'F');
				
				printf("Digite o setor do funcionário: ");
				scanf(" %[^\n]", funcionarios[i].setor);
				
				printf("Digite o salário do funcionário: ");
				scanf("%f",&funcionarios[i].salario);
				
				qtd++;
			break;
			
			case 2:
				opR = 0;
				while (opR != 6)
				{
					printf("\n==== RELATÓRIOS ====\n");
					printf("1- Quantidade de funcionários por sexo.\n2- Funcionário mais novo e mais velho.\n3- Média de idade por setor.\n4- Funcionários por ordem crescente de salário.\n5- Funcionários por sexo em ordem decrescente de idade.\n6- Retornar ao menu anterior.\nDigite sua opção: ");
					scanf("%i",&opR);
					
					switch (opR)
					{
						case 1:
							contM = 0;
							contF = 0;
							for (int x = 0; x < qtd; x++)
							{
								if (funcionarios[x].sexo == 'M')
								{
									contM += 1;
								}
								else contF +=1;
							}
							printf("\nFuncionários do sexo masculino: %i\nFuncionários do sexo feminino: %i\n", contM, contF);
						break;
						
						case 2:
							maior = 0;
						    menor = 0;
						    for (int x = 1; x < qtd; x++)
						    {
						        if (funcionarios[x].idade > funcionarios[maior].idade)
						        {
						            maior = x;
						        }
						
						        if (funcionarios[x].idade < funcionarios[menor].idade)
						        {
						            menor = x;
						        }
						    }
						    printf("\nFuncionário mais novo: %s\nFuncionário mais velho: %s\n", funcionarios[menor].nome, funcionarios[maior].nome);
						break;
						
						case 3:
							
						break;
						
						case 4:
							contPos = 1;
							while (contPos != 0)
							{
								maiorSal = 0;
								for (int contPos = 0; contPos < qtd; contPos++)
								{
									if (funcionarios[contPos].salario > maiorSal)
									{
										maiorSal = funcionarios[contPos].salario;
										maiorFunc = funcionarios[contPos];
										posSal = contPos;
									}
								}
								contPos--;
								funcionarios[posSal] = funcionarios[contPos];
								funcionarios[contPos] = maiorFunc;
							}
							
							printf("\nFuncionários por ordem crescente de salário:\n");
							for (int x = 0; x < qtd; x++)
							{
								printf("%iº: %s, %i anos\n",(x+1), funcionarios[x].nome, funcionarios[x].idade);
							}
						break;
						
						case 5:
							contPos = 1;
							/* while (contPos != 0)
							{
								maiorSal = 0;
								for (int contPos = 0; contPos < qtd; contPos++)
								{
									if (funcionarios[contPos].salario > maiorSal)
									{
										maiorSal = funcionarios[contPos].salario;
										maiorFunc = funcionarios[contPos];
										posSal = contPos;
									}
								}
								contPos--;
								funcionarios[posSal] = funcionarios[contPos];
								funcionarios[contPos] = maiorFunc;
							} */
							printf("\nFuncionários por sexo em ordem decrescente de idade:\n")
						break;
						
						case 6:
							printf("Voltando!\n");
						break;
						
						default:
							printf("Opção inválida!\n");
						break;
					}
				}
			break;
			
			default:
				printf("Opção inválida!\n");
			break;
		}
		
		if (op==0) break;
	}
	
}
