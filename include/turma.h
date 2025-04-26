#ifndef TURMA_H
#define TURMA_H
#include "aluno.h"

typedef struct{
    Aluno listaAlunos[100];
    int numeroAlunos;
     
} Turma;

int tamanho(Turma *turma);
int buscar(Turma *turma, char matricula[20]);
void reinicializar(Turma *turma);
void exibirLista(Turma *turma);
int inserir(Turma *turma, Aluno aluno, int posicao);
int remover(Turma *turma, char matricula[20]);
#endif