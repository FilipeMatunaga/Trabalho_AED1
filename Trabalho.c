#include <stdio.h>

int main(){
    printf("Bem-Vindo ao sistema de matrícula em cursos do INF.\n");
    while(1){
        printf("Digite o número para a função desejada:\n");
        printf("1. Matricular aluno em um curso.\n");
        printf("2. Desmatricular aluno de um curso.\n");
        printf("3. Buscar dados do aluno.\n");
        printf("4. Editar dados do aluno.\n");
        printf("5. Consultar quantidade de alunos por curso.\n");
        printf("6. Sair.\n");
        int n;
        scanf("%d", &n);
        switch (n){
            case 1:
                /* code */
                break;
            case 2:
                /* code */
                break;
            case 3:
                /* code */
                break;
            case 4:
                /* code */
                break;
            case 5:
                /* code */
                break;
            case 6:
                return 0;
                break;
            default:
                printf("Número inválido.\n");
                break;
        }
    }
}
