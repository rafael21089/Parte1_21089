#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Operacao.h"
#include "Trabalho.h"
#include <stdbool.h>
#include <string.h> 


void CreateOperations(Operation** operation, int iD, int time, char* name) {

	//Variaveis Operation
	Operation* newOperation = (Operation*)malloc(sizeof(Operation));
	Operation* last = *operation;

	//Initializar uma nova maquina para as operacoes
	newOperation->ID = iD;
	strcpy(newOperation->Name, name);
	newOperation->Time = time;
	newOperation->next = NULL;

	//Verificar se esta nula
	if (isEmpty(*operation))
	{
		*operation = newOperation;
		return;
	}

	//Se nao estiver null encontrar a ultima
	while (last->next != NULL)
	{
		last = last->next;
	}

	//Igualar a ultima a nova maquina
	last->next = newOperation;
}

//Modificar a operacao
void ModifyOperation(Operation* actualOperation, Operation newOperation)
{
	//Variaveis
	Operation* modify;
	bool editada = false;

	//Igualar a actual 
	modify = actualOperation;

	// encontrar a maquina pretendida
	while (modify != NULL && editada == false)
	{
		if (modify->ID == newOperation.ID)
		{
			// modificar a maquina
			*modify = newOperation;
			editada = true;
		}
		modify = modify->next;
	}
}

//Escreve no file
void WriteOperations(Operation* operation, int id_jogo)
{
	//Variaveis
	Operation* actual;

	//Inicializar a variavel actual
	actual = operation;

	//Da open do file
	FILE* in;

	in = fopen("Process_Plan.txt", "w");
	if (in == NULL)
	{
		printf("ERRO: não consigo abrir o ficheiro dados.txt\n");
	}

	fprintf(in, "\nJob Number: %d \n", id_jogo);

	while (actual != NULL)
	{
		//Escreve no file
		fprintf(in,"\nOp: %d, Time: %d, Name: %s \n", actual->ID, actual->Time, actual->Name);

		//Passa para o proximo
		actual = actual->next;
	}

	//Close file
	fclose(in);
}

//Obter a operation
Operation getOperation(Operation* operationHead, int id)
{
	//Variaveis
	Operation* actual, * operationFound;

	//Inicializar
	operationFound = NULL;

	//Inicializar a variavel atual
	actual = operationHead;

	//Precorer operations
	while (actual != NULL && operationFound == NULL)
	{
		//Verificar se é o produto pretendido
		if (actual->ID == id)
			operationFound = actual;

		//Ir para o proximo produto
		actual = actual->next;
	}

	//Se não encontrar nenhum produto
	if (operationFound == NULL)
	{
		printf("\nThe operation %d dont exist\n", id);
		return;
	}

	//Retornar o produto
	return *operationFound;

}

//Remove uma operacao
void removeOperation(Operation* operationHead, int id) {

	if (isEmpty(operationHead)) {
		printf("\na lista está vazia...\n");
		return;
	}

	if (operationHead->ID == id) {
		//remove no inicio da lista
		Operation* aux = operationHead;
		operationHead = operationHead->next;
		free(aux);
	}
	else
	{
		Operation* aux = operationHead;
		Operation* newaux = aux;

		//procura para dar remove
		while (aux && aux->ID != id) {	
			newaux = aux;
			aux = aux->next;
		}
		if (aux != NULL) {					
			newaux->next = aux->next;
			free(aux);
		}//Se encontrou, remove
	}
}

//Calcula a media de o tempo de todas as operacoes
float calcularMediaOperations(Operation* operation)
{
	//Variaveis
	Operation* actual;
	int sumTime = 0;
	int numberOfOperations = 0;

	//Inicializar a variavel actual
	actual = operation;

	while (actual != NULL)
	{
		//Soma
		sumTime += actual->Time;
		numberOfOperations += 1;

		//Passar next
		actual = actual->next;
	}

	//Media
	float media = sumTime / (float)numberOfOperations;

	return media;
}

//Calcula o minimo tempo de uma operacao
float MinimoTempoOperacao(Operation* operation, int id)
{
	//Variaveis
	Operation* actual;
	int sumTime = 0;
	int numberOfOperations = 0;

	//Inicializar a variavel actual
	actual = operation;

	//Valor inicial para nao ser vazio
	int minimototal = 1000;

	while (actual != NULL)
	{
		//Ve todos os que tem o mesmo id de operacao
		if (actual->ID == id)
		{
			//Se for menor entra para o minimo total
			if (actual->Time < minimototal)
			{
				minimototal = actual->Time;
			}

			//Next 
			actual = actual->next;
		}
		else
		{

			//Next 
			actual = actual->next;
		}
	}


	return minimototal;
}

//Calcula o maximo tempo de uma operacao
float MaximoTempoOperacao(Operation* operation, int id)
{
	//Variaveis
	Operation* actual;
	int sumTime = 0;
	int numberOfOperations = 0;

	//Inicializar a variavel actual
	actual = operation;

	//Valor inicial para nao ser vazio
	int maximototal = 1;

	while (actual != NULL)
	{
		//Ve todos os que tem o mesmo id de operacao
		if (actual->ID == id)
		{
			//Se for maior entra para o minimo total
			if (actual->Time > maximototal)
			{
				maximototal = actual->Time;
			}

			//Next 
			actual = actual->next;
		}
		else
		{
			//Next 
			actual = actual->next;
		}
	}


	return maximototal;
}

//Quantas operacoes existem
float NumeroDeOperacoes(Operation* operation)
{
	//Variaveis
	Operation* actual;

	//Inicializar a variavel actual
	actual = operation;
	int id_anterior = 0;
	int numberOfOperations = 0;

	while (actual != NULL)
	{
		//Compara ids
		if (actual->ID != id_anterior)
		{
			numberOfOperations += 1;
			id_anterior = actual->ID;
		}

		//Next
		actual = actual->next;
	}

	return numberOfOperations;
}


//Ver se a lista está vazia
bool isEmpty(Operation* operation)
{
	//Verificar se a lista está vazia
	if (operation == NULL)
		return true;
	else
		return false;
}