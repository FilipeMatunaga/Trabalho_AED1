
typedef struct{
    id string;
    string nome;
    string professor;
    string horario;
    local local;
    char turma;
    int duracao_total;
    int vagas_totais;
    int vagas_ocupadas;
    int ano;
    int periodo;
}materia;

typedef struct{
    int sala;
    string predio;
    string campus;
    string cidade;
}local;
