#include "Trabalho.h"
#include "Operacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)


int main() {

	//Variaveis
	Job* jobs;
	Operation* operation;
	Operation operation_alter;
	int esc = 0;
	int size;

	// Inicializar listas
	jobs = NULL;
	operation = NULL;

	// Criar o job
	CreateJob(&jobs, 1);

	//Variaveis para a escolha 1
	int operacao_id = 1;
	char nome_operacao[50];
	int tempo=0;
	char continuar_add[1];

	//Variaveis para a escolha 2
	int tempo_alter=0;
	int operacao_alter_id=0;
	char nome_alter[50];

	//Variaveis para a escolha 3
	int elim;

	//Variaveis para a escolha 4 
	float minimototal = 0;
	int minimo = 0;

	//Variaveis para a escolha 5 
	float maximototal = 0;
	int maximo = 0;

	//Variaveis para a escolha 6 
	float calculaMedia;

	//loop para escolha
	do
	{
		bool loopadd = false;

		printf("\n\n----------- ");
		printf("\n\nOpcoes: ");
		printf("\nInserir Operacao em um Job: 1");
		printf("\nAlterar Operacao em um Job: 2");
		printf("\nEliminar Operacao em um Job: 3");
		printf("\nTempo minimo de uma operacao: 4");
		printf("\nTempo maximo de uma operacao: 5");
		printf("\nMedia da operacao: 6");
		printf("\n\nEscolha: ");
		scanf("%d", &esc);

		switch (esc)
		{
			case 1:

				while (loopadd == false)
				{
					printf("\nNome para operacao: ");
					scanf("%s", &nome_operacao);
					printf("\nTempo da operacao: ");
					scanf("%d", &tempo);

					//Cria e da Add
					CreateOperations(&operation, operacao_id, tempo, nome_operacao);
					AddOperations(jobs, 1, operation);

					printf("\nQuer continuar a adicionar para a O%d (S ou N): ", operacao_id);
					scanf("%s", &continuar_add);

					if (continuar_add[0] == 115) // Se escolher 's' continua
					{
						loopadd = false;
					}
					else
					{
						operacao_id++;
						loopadd = true;
					}
				}
				
				
				system("cls");

			break;

			
			case 2:
				printf("\nQue operacao quer alterar: ");
				scanf("%d", &operacao_alter_id);

				printf("\nQue nome a operacao tem: ");
				scanf("%s", &nome_alter);
				printf("\nQue tempo quer: ");
				scanf("%d", &tempo_alter);

				//Para obter a operation e alterar o nome e o tempo
				operation_alter = getOperation(jobs->OperationsList, operacao_alter_id);
				operation_alter.Time = tempo_alter;
				strcpy(operation_alter.Name, nome_alter);

				ModifyOperation(jobs->OperationsList, operation_alter);

				system("cls");
				break;

			case 3:

				printf("\nQue operacao quer eliminar: ");
				scanf("%d", &elim);

				//Elimina a operacao
				removeOperation(jobs->OperationsList, elim);

				system("cls");
				break;

			case 4:

				system("cls");

				//Quantas operacoes existem
				size = NumeroDeOperacoes(operation); 

				for (int i = 1; i <= size; i++)
				{
					//Da get de o Minimo de cada operacao e adiciona ao minimo total
					minimo = MinimoTempoOperacao(operation, i);
					printf("\n O%d: %d",i, minimo);

					minimototal = minimototal + minimo;
				}

				//Media
				minimototal = minimototal / size;

				printf("\nMinimo total: %.2f", minimototal);


				break;

			case 5:

				system("cls");

				//Quantas operacoes existem
				size = NumeroDeOperacoes(operation);

				for (int i = 1; i <= size; i++)
				{
					//Da get de o Maximo de cada operacao e adiciona ao minimo total
					maximo = MaximoTempoOperacao(operation, i);
					printf("\n O%d: %d", i, maximo);

					maximototal = maximototal + maximo;
				}

				//Media
				maximototal = maximototal / size;

				printf("\nMaximo total: %.2f", maximototal);

				break;

			case 6:
				system("cls");
				
				//Media de todas as operacoes
				calculaMedia = calcularMediaOperations(operation);
				printf("Tempo medio operacoees %.2f \n", calculaMedia);

				break;
		}

		//Da add ao job no documento texto
		WriteJob(jobs);

		//Mostra o documento texto
		Leitura_textfile();

	} while (true);


	return 0;
}