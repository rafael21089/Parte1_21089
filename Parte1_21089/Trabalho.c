#define _CRT_SECURE_NO_WARNINGS
#include "Trabalho.h"
#include "Operacao.h"
#include <stdbool.h>

//Cria Job
void CreateJob(Job** job, int iD) {

	//Variaveis para um new Job
	Job* newJob = (Job*)malloc(sizeof(Job));
	Job* last = *job;

	//Dados
	newJob->ID = iD;
	newJob->OperationsList = NULL;
	newJob->next = NULL;

	if (IsEmpty(*job))
	{
		*job = newJob;
		return;
	}

	while (last->next != NULL)
	{
		last = last->next;
	}

	//Next
	last->next = newJob;


}


//Adiciona Operacoes
void AddOperations(Job* job, int iD, Operation* operations)
{
	//Variaveis
	Job* actual;
	bool edited = false;

	//Igualar a atual a recebida
	actual = job;

	//Encontrar o id pretendido
	while (actual != NULL && edited == false)
	{
		if (actual->ID == iD)
		{
			actual->OperationsList = operations;
			edited = true;
		}
		actual = actual->next;
	}
}

//Ver se a lista está vazia
bool IsEmpty(Job* job)
{
	//Verificar se a lista está vazia
	if (job == NULL)
		return true;
	else
		return false;
}

//Escreve o Job
void WriteJob(Job* job)
{
	//Variaveis
	Job* actual;
	int count = 0;

	actual = job;

	while (actual != NULL)
	{
		
		//Se nao tiver operations
		if (actual->OperationsList == NULL)
		{
			printf("No Operations");
		}
		else
		{
			//Escrever no textfile
			WriteOperations(actual->OperationsList, actual->ID);
		}

		//Next
		actual = actual->next;
	}


}

//Le o textfile
void Leitura_textfile() {

	FILE* in;
	char texto_str[40];

	in = fopen("Process_Plan.txt", "r");
	if (in == NULL)
	{
		printf("ERRO: não consigo abrir o ficheiro dados.txt\n");
	}

	while (fgets(texto_str, 40, in) != NULL) {
		printf("%s", texto_str);
	}

	fclose(in);

}
