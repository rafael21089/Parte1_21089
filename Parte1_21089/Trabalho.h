#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Operacao.h"

typedef struct job {
	int ID;
	struct Operation* OperationsList;
	struct job* next;
}Job;



void CreateJob(Job** actualJob, int iD);
void WriteJob(Job* job);
bool IsEmpty(Job* job);
void AddOperations(Job* job, int iD, Operation* operations);
void Leitura_textfile();