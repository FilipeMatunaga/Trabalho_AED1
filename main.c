#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ----------------------------------
// ----------- STRUCTS --------------

typedef struct aluno{
    char nome[200];
    char CPF[14];
    char email[200];
    struct aluno* prox;
} aluno;

typedef struct alunos_curso{
    aluno* inicio;
    aluno* fim;
    int tamanho;
} alunos_curso;

typedef struct curso{
    char nome[200];
    int id;
    alunos_curso* alunos_do_curso;
    struct curso* prox;
} curso;

typedef struct cursos_inf{
    curso* inicio;
    curso* fim;
} cursos_inf;

typedef struct instituto_informatica{
    char nome[200];
    cursos_inf* cursos;
} instituto_informatica;

// -----------------------------------------------
// ---------------- FUNÇÕES ----------------------


alunos_curso* criar_alunos_curso(){
    alunos_curso* alunos_criado = malloc(sizeof(alunos_curso));
    alunos_criado->inicio = alunos_criado->fim = NULL;
    alunos_criado->tamanho = 0;
    return alunos_criado;
}

instituto_informatica* criar_inf(){
    instituto_informatica* inf = malloc(sizeof(instituto_informatica));
    inf->cursos = malloc(sizeof(cursos_inf));
    inf->cursos->inicio = inf->cursos->fim = NULL;
    strcpy(inf->nome, "Instituto de Informática");
    return inf;
}

int criar_curso(char nome[200], int id, instituto_informatica* inf){
    curso* curso_criado = malloc(sizeof(curso));
    if(curso_criado == NULL) return 0;

    curso_criado->id = id;
    strcpy(curso_criado->nome, nome);
    curso_criado->prox = NULL;
    curso_criado->alunos_do_curso = criar_alunos_curso();

    if(inf->cursos->inicio == NULL){
        inf->cursos->inicio = inf->cursos->fim = curso_criado;
        return 1;
    }

    inf->cursos->fim->prox = curso_criado;
    inf->cursos->fim = curso_criado;

    return 1;
}

int adicionar_aluno(aluno aluno_adicionar, instituto_informatica *inf, int id){
    // printf("Aluno matriculado com sucesso!\n");
    aluno* aluno_novo = malloc(sizeof(aluno));

    *aluno_novo = aluno_adicionar;
    aluno_novo->prox = NULL;

    curso* curso_atual = inf->cursos->inicio;
    while (curso_atual != NULL && curso_atual->id != id){
        curso_atual = curso_atual->prox;
    }

    alunos_curso* lista = curso_atual->alunos_do_curso;
    lista->tamanho++;
    system("clear");
    printf("\n\nAluno matriculado com sucesso!\n");

    if(lista->inicio == NULL){
        lista->inicio = lista->fim = aluno_novo;
        return 1;
    }

    lista->fim->prox = aluno_novo;
    lista->fim = aluno_novo;

    return 1;
}


int desmatricular_aluno(char cpf[14], instituto_informatica* inf, int id){
    curso* c = inf->cursos->inicio;

    while(c != NULL && c->id != id){
        c = c->prox;
    }

    aluno* atual = c->alunos_do_curso->inicio;
    aluno* anterior = NULL;

    while(atual != NULL && strcmp(atual->CPF, cpf) != 0){
        anterior = atual;
        atual = atual->prox;
    }

    if(atual == NULL){
        system("clear");
        printf("\n\nAluno não encontrado!\n\n");
        return 0;
    }

    system("clear");
    printf("Aluno desmatriculado com sucesso!\n");
    
    c->alunos_do_curso->tamanho--;

    if(anterior == NULL){
        c->alunos_do_curso->inicio = atual->prox;
        if(atual == c->alunos_do_curso->fim)
            c->alunos_do_curso->fim = NULL;
    } else {
        anterior->prox = atual->prox;
        if(atual == c->alunos_do_curso->fim)
            c->alunos_do_curso->fim = anterior;
    }

    free(atual);
    return 1;
}

void printar_id_curso(){
    printf("\n------- IDs dos cursos ------\n");
    printf("1 - Engenharia de Software\n");
    printf("2 - Ciência da Computação\n");
    printf("3 - Sistemas de Informação\n");
    printf("4 - Inteligência Artificial\n\n");
}

aluno* buscar_aluno(char cpf[14], instituto_informatica* inf){
    curso* c = inf->cursos->inicio;

    while(c != NULL){
        aluno* a = c->alunos_do_curso->inicio;

        while(a != NULL){
            if(strcmp(a->CPF, cpf) == 0)
                return a;
            a = a->prox;
        }
        c = c->prox;
    }
    return NULL;
}

int editar_aluno(char cpf[14], instituto_informatica* inf){
    aluno* a = buscar_aluno(cpf, inf);
    if(a == NULL){
        system("clear");
        printf("\n\nAluno não encontrado!\n");
        return 0;
    }

    printf("Novo nome: ");
    scanf("%199s", a->nome);

    printf("Novo email: ");
    scanf("%199s", a->email);

    system("clear");
    printf("\n\nDados editados com sucesso!\n\n");


    return 1;
}

int quantidade_alunos_por_curso(instituto_informatica* inf, int id){
    curso* c = inf->cursos->inicio;

    while(c != NULL && c->id != id){
        c = c->prox;
    }

    int count = c->alunos_do_curso->tamanho;
    return count;
}

int menu(instituto_informatica* inf){
    printf("\nDigite o número para a função desejada:\n");
    printf("----------------------------------------------\n");
    printf("1 - Matricular aluno em um curso.\n");
    printf("2 - Desmatricular aluno de um curso.\n");
    printf("3 - Buscar dados do aluno.\n");
    printf("4 - Editar dados do aluno.\n");
    printf("5 - Consultar quantidade de alunos por curso.\n");
    printf("6 - Sair.\n");
    printf("----------------------------------------------\n");

    int n;
    scanf("%d", &n);
    getchar();

    system("clear");

    switch (n){
        case 1:{
            printar_id_curso();
            int id;
            printf("ID do curso: ");
            scanf("%d", &id);
            getchar();

            system("clear");

            aluno novo;
            printf("Nome: ");
            scanf("%199s", novo.nome);
            printf("CPF: ");
            scanf("%14s", novo.CPF);
            printf("Email: ");
            scanf("%199s", novo.email);

            adicionar_aluno(novo, inf, id);
            break;
        }

        case 2:{
            char cpf[14];
            int id;
            printf("CPF do aluno: ");
            scanf("%14s", cpf);
            printar_id_curso();
            printf("ID do curso: ");
            scanf("%d", &id);
            getchar();

            system("clear");

            desmatricular_aluno(cpf, inf, id);
            break;
        }

        case 3:{
            char cpf[14];
            printf("CPF: ");
            scanf("%14s", cpf);

            aluno* a = buscar_aluno(cpf, inf);

            system("clear");

            if(a == NULL) printf("\n\nAluno não encontrado.\n\n");
            else printf("\nNome: %s\nEmail: %s\n\n", a->nome, a->email);
            break;
        }

        case 4:{
            char cpf[14];
            printf("CPF: ");
            scanf("%14s", cpf);

            system("clear");

            editar_aluno(cpf, inf);
            break;
        }

        case 5:{
            printar_id_curso();
            int id;
            printf("ID do curso: ");
            scanf("%d", &id);
            getchar();

            system("clear");

            int qtd = quantidade_alunos_por_curso(inf, id);
            printf("Quantidade de alunos no curso: %d\n", qtd);
            break;
        }

        case 6:
            return 0;

        default:
            system("clear");
            printf("\n\nNúmero inválido!\n");
    }
    return 1;
}

void limpar(){
    
    printf("\n\nInsira 0 para voltar ao menu principal.\n\n");
    // printf("----------------------------------------\n");
    int c;
    scanf("%d", &c);
    system("clear");
}

//------------------------------------------------
// -------------------- MAIN -------------------- 

int main(){
    instituto_informatica* inf = criar_inf();
    char nome[200];
    strcpy(nome, "Engenharia de Software");
    criar_curso(nome, 1, inf);
    strcpy(nome, "Ciência da Computação");
    criar_curso(nome, 2, inf);
    strcpy(nome, "Sistemas de Informação");
    criar_curso(nome, 3, inf);
    strcpy(nome, "Inteligência Artificial");
    criar_curso(nome, 4, inf);
    
    printf("Olá! Seja bem vindo ao nosso sistema de matrículas.\n");
    int num;    

    while (1){
        int num = (menu(inf));

        if(num == 0){
            printf("Progama finalizado!\n");
            break;
        } else{
            limpar();
        }


    }   

    return 0;
}
