#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct aluno{
    char nome[200];
    char CPF[14];
    char email[200];
    char telefone[13];
    int idade;
    int id;
    struct aluno* prox;
} aluno;

typedef struct alunos_curso{
    aluno* inicio;
    aluno* fim;
} alunos_curso;

typedef struct curso{
    char nome[200];
    int id;
    int carga_horaria;
    alunos_curso* alunos_do_curso;
} curso;

typedef struct cursos_inf{
    curso* inicio;
    curso* fim;
} cursos_inf;

typedef struct instituto_informatica{
    char nome[200];
    cursos_inf* cursos;
} instituto_informatica;

#endif
