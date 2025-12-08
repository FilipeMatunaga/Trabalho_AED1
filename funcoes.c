#include "structs.h"
#include <stdlib.h>
#include <string.h>


alunos_curso* criar_alunos_curso(){
    alunos_curso* alunos_criado = malloc(sizeof(alunos_curso));
    alunos_criado->inicio = NULL;
    alunos_criado->fim = NULL;
    return alunos_criado;
}

curso* criar_curso(char nome[200], int carga_horaria){
    curso* curso_criado = malloc(sizeof(curso));
    curso_criado->alunos_do_curso = criar_alunos_curso();
    strcpy(curso_criado->nome, nome);
    curso_criado->carga_horaria = carga_horaria;
    return curso_criado;
}

instituto_informatica* criar_inf(){
    instituto_informatica* inf = malloc(sizeof(instituto_informatica));
    strcpy(inf->nome, "Instituto de Informática");
    return inf;
}

int push_back(aluno aluno_adicionar, alunos_curso* alunos_curso){
    aluno* aluno_novo = malloc(sizeof(aluno));

    if(aluno_novo == NULL) return 0;
    *aluno_novo = aluno_adicionar;
    aluno_novo->prox = NULL;

    if(alunos_curso->inicio == NULL){
        alunos_curso->inicio = alunos_curso->fim = aluno_novo;
        return 1;
    }

    alunos_curso->fim->prox = aluno_novo;
    alunos_curso->fim = aluno_novo;
    return 1;
}   
