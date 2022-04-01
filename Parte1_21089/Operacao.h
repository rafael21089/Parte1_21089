#pragma once
#include <stdbool.h>
#include <string.h> 

#define MAX 50

typedef struct operation {
	int ID;
	int Time;
	char Name[MAX];
	struct operation* next;
} Operation;

void CreateOperations(Operation** operation, int iD, int time, char* name);
void ModifyOperation(Operation* actualOperation, Operation newOperation);
Operation getOperation(Operation* operationHead, int id);
void WriteOperations(Operation* operation, int id_jogo);
bool isEmpty(Operation* operation);
void removeOperation(Operation* operationHead, int id);
float calcularMediaOperations(Operation * operation); 
float MinimoTempoOperacao(Operation* operation, int id);
float MaximoTempoOperacao(Operation* operation, int id);
float NumeroDeOperacoes(Operation* operation);
