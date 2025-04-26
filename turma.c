#include "turma.h"
#include "aluno.h"
#include <stdio.h>
#include <string.h>

// Passando Turma por ponteiro para modificar diretamente
int tamanho(Turma *turma)
{
    return turma->numeroAlunos;
}

int buscar(Turma *turma, char chave[20])
{
    for (int i = 0; i < turma->numeroAlunos; i++)
    {
        if (strcmp(chave, turma->listaAlunos[i].matricula) == 0)
        {
            return i;
        }
    }
    return -1;
}

void exibirLista(Turma *turma)
{
    printf("Lista : \n");
    for (int i = 0; i < turma->numeroAlunos; i++)
    {
        printf("%s\n", turma->listaAlunos[i].matricula);
    }
}

int inserir(Turma *turma, Aluno aluno, int posicao)
{
    int j;
    if ((turma->numeroAlunos == 100) || (posicao < 0) || (posicao > turma->numeroAlunos))
    {
        return -1;
    }

    for (j = turma->numeroAlunos; j > posicao; j--)
    {
        turma->listaAlunos[j] = turma->listaAlunos[j - 1];
    }

    turma->listaAlunos[posicao] = aluno;
    turma->numeroAlunos++;
    return 1;
}

int remover(Turma *turma, char matricula[20])
{
    int pos, j;
    pos = buscar(turma, matricula);

    if (pos == -1)
    {
        return -1;
    }
    for (j = pos; j < turma->numeroAlunos - 1; j++)
    {
        turma->listaAlunos[j] = turma->listaAlunos[j + 1];
    }

    turma->numeroAlunos--;
    return 1;
}

void reinicializar(Turma *turma)
{
    turma->numeroAlunos = 0;
}
