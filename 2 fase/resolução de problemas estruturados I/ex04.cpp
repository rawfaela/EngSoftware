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
#include <string.h>

typedef struct Funcionario
{
	char nome[50], setor[50], sexo;
	int idade;
	float tempo, salario;
} FUNCIONARIO;

typedef struct Setores
{
	char nome[50];
	int qtd, somaIdade;
} SETORES;

int main()
{
	setlocale(LC_ALL,"Portuguese");
	
	FUNCIONARIO funcionarios[10], maiorFunc, funcsF[10], funcsM[10];
	SETORES setores[10];
	int op = 1, opR, contM, contF, qtd = 0, maior, menor, posAux, contPos, qtdSetores;
	float maiorAux;
	bool encontrou;

	while(op!=0)
	{
		printf("\n==== MENU ====\n");
		printf("0- Sair\n1- Informar dados dos funcionários\n2- Relatórios\nDigite sua opção: ");
		scanf("%i",&op);
		
		switch (op)
		{
			case 0:
				printf("\nSaindo!\n");
			break;
			
			case 1:
				if (qtd >= 10)
				{
					printf("Limite de funcionários atingido!\n");
				}
				else
				{
					printf("Digite o nome do funcionário: ");
					scanf(" %[^\n]", funcionarios[qtd].nome);
					
					printf("Digite a idade do funcionário: ");
					scanf("%i",&funcionarios[qtd].idade);
					
					printf("Digite o tempo de empresa do funcionário: ");
					scanf("%f",&funcionarios[qtd].tempo);
					
					do 
					{
						printf("Digite o sexo do funcionário (M/F): ");
						scanf(" %c",&funcionarios[qtd].sexo);
						funcionarios[qtd].sexo = toupper(funcionarios[qtd].sexo);
						if (funcionarios[qtd].sexo != 'M' && funcionarios[qtd].sexo != 'F')
						{
							printf("Sexo inválido.\n");
						}
					} while (funcionarios[qtd].sexo != 'M' && funcionarios[qtd].sexo != 'F');
					
					printf("Digite o setor do funcionário: ");
					scanf(" %[^\n]", funcionarios[qtd].setor);
					
					printf("Digite o salário do funcionário: ");
					scanf("%f",&funcionarios[qtd].salario);
					
					qtd++;
				}
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
							if (qtd == 0)
							{
								printf("Nenhum funcionário cadastrado!\n");
								break;
							}
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
							printf("\nQuantidade de funcionários por sexo:\n");
							printf("Funcionários do sexo masculino: %i\nFuncionários do sexo feminino: %i\n", contM, contF);
						break;
						
						case 2:
							if (qtd == 0)
							{
								printf("Nenhum funcionário cadastrado!\n");
								break;
							}
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
						    printf("\nFuncionário mais novo e mais velho:\n");
						    printf("Funcionário mais novo: %s\nFuncionário mais velho: %s\n", funcionarios[menor].nome, funcionarios[maior].nome);
						break;
						
						case 3:
							if (qtd == 0)
							{
								printf("Nenhum funcionário cadastrado!\n");
								break;
							}
							qtdSetores = 0;

							for (int x = 0; x < 10; x++)
							{
								setores[x].qtd = 0;
								setores[x].somaIdade = 0;
							}

							for (int x = 0; x < qtd; x++)
							{
								encontrou = 0;
								for (int y = 0; y < qtdSetores; y++)
								{
									if (strcmp(funcionarios[x].setor, setores[y].nome) == 0)
									{
										setores[y].qtd++;
										setores[y].somaIdade += funcionarios[x].idade;
										encontrou = 1;
										break;
									}
								}

								if (!encontrou)
								{
									strcpy(setores[qtdSetores].nome, funcionarios[x].setor);
									setores[qtdSetores].qtd = 1;
									setores[qtdSetores].somaIdade = funcionarios[x].idade;
									qtdSetores++;
								}
							}

							printf("\nMédia de idade por setor:\n");
							for (int x = 0; x < qtdSetores; x++)
							{
								printf("Setor %s: %.2f anos\n", setores[x].nome, (float)setores[x].somaIdade / setores[x].qtd);
							}

						break;
						
						case 4:
							if (qtd == 0)
							{
								printf("Nenhum funcionário cadastrado!\n");
								break;
							}
							contPos = qtd-1;
							while (contPos >= 0)
							{
								maiorAux = 0;
								for (int x = 0; x <= contPos; x++)
								{
									if (funcionarios[x].salario > maiorAux)
									{
										maiorAux = funcionarios[x].salario;
										maiorFunc = funcionarios[x];
										posAux = x;
									}
								}
								funcionarios[posAux] = funcionarios[contPos];
								funcionarios[contPos] = maiorFunc;
								contPos--;
							}
							
							printf("\nFuncionários por ordem crescente de salário:\n");
							for (int x = 0; x < qtd; x++)
							{
								printf("%iº: %s, %i anos\n",(x+1), funcionarios[x].nome, funcionarios[x].idade);
							}
						break;
						
						case 5:
							if (qtd == 0)
							{
								printf("Nenhum funcionário cadastrado!\n");
								break;
							}
							contPos = qtd-1;
							while (contPos >= 0)
							{
								maiorAux = 0;
								for (int x = 0; x <= contPos; x++)
								{
									if (funcionarios[x].idade > maiorAux)
									{
										maiorAux = funcionarios[x].idade;
										maiorFunc = funcionarios[x];
										posAux = x;
									}
								}
								funcionarios[posAux] = funcionarios[contPos];
								funcionarios[contPos] = maiorFunc;
								contPos--;
							}

							contF = 0;
							contM = 0;
							for (int x = 0; x < qtd; x++)
							{
								if (funcionarios[x].sexo == 'F')
								{
									funcsF[contF] = funcionarios[x];
									contF++;
								}
								else
								{
									funcsM[contM] = funcionarios[x];
									contM++;
								}
							}

							printf("\nFuncionários por sexo em ordem decrescente de idade:\n");
							printf("Sexo feminino:\n");
							for (int x = (contF - 1); x >= 0; x--)
							{
								printf("%iº: %s, %i anos\n",(x+1), funcsF[x].nome, funcsF[x].idade);
							}
							printf("Sexo masculino:\n");
							for (int x = (contM - 1); x >= 0; x--)
							{
								printf("%iº: %s, %i anos\n",(x+1), funcsM[x].nome, funcsM[x].idade);
							}
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
	}
}
