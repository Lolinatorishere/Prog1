#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define isasciinum(STRING)\
    if(STRING >= 48 && STRING <= 57)

//1. Implementar um programa que escreva para o ficheiro de texto “curriculum.txt”
//o nome do curso que frequenta no cabeçalho. Em seguida (linha abaixo) deverá
//escrever o seu número e nome e nas linhas seguintes deverá escrever listas de
//disciplinas que já terminou no curso e respetiva nota (uma por linha).
//
//2. Implementar um programa que imprima para o ecrã o conteúdo de um ficheiro
//de texto. O nome do ficheiro é fornecido pelo utilizador (incluindo a extensão do
//ficheiro).
//
//3. Implemente um programa que escreve para o ficheiro “numMul7.txt” os
//números múltiplos de 7 existentes entre 300 e 600. Escreva um número em cada
//linha.
//
//4. Implemente um que programa que permita pedir ao utilizador e guardar num
//ficheiro de texto o número do aluno, nota 1º teste, nota 2º teste e nota trabalho
//prático de uma lista de alunos. O nome do ficheiro deve ser introduzido pelo
//utilizador. Os valores referentes a um aluno devem ser escritos numa linha e
//devem ser separados por ‘;’. O programa termina quando introduzir o aluno
//número 0.
//Exemplo de ficheiro:
//2345;12;10;14
//1234;11;13;18
//2340;10;15;17
//4567;16;17;16
//
//5. Implementar um programa que permita ler o ficheiro criado no exercício anterior
//e enviar para o ecrã o nº dos alunos com Nota Final (NF) positiva, sabendo que
//NF=25%teste1+25%teste2+50%TP. No final deverá apresentar a quantidade de
//alunos aprovados.
//
//6. Implementar um programa que permita ler o ficheiro criado no exercício 4 e
//escrever para o ecrã:
//a. a média das notas por avaliação (teste 1, teste 2 e TP).
//b. Nº do(s) aluno(s) com nota to TP mais alta.
//c. Nº do(s) aluno(s) com nota mais baixa no teste1.
//
//7. Implementar um programa que permita guardar num ficheiro de texto a lista de
//pessoas inscritas na cimeiraIPVC2025. O programa deverá permitir acrescentar
//novas inscrições e listar inscrições feitas até ao momento. O nome do ficheiro
//deverá ser “CimeiraIPVC2025.txt”.
//a. Inserir nova inscrição - O programa deverá pedir ao utilizador o nome,
//nº de telefone, nome instituição de proveniência do participante que se
//pretende inscrever. A informação de um participante será escrita numa
//linha. A inserção terminará quando o utilizador digitar a palavra ‘FIM’.
//A docente: Estrela Ferreira Cruz
//Deverá ser possível acrescentar novas inscrições ao ficheiro sempre que
//necessário. Sempre que um novo elemento se inscreve é-lhe fornecido
//um número de inscrição.
//b. Listar inscrições feitas até ao momento - O programa deverá ler o
//ficheiro criado no exercício anterior e imprimir para o ecrã o conteúdo do
//ficheiro de texto.
//c. Alterar os dados de inscrição de um participante, dado o número de
//inscrição.
//
//8. Implementar o comando cp do Unix: O programa deverá receber na linha de
//comando o nome do ficheiro original e o nome do ficheiro final e deve copiar o
//conteúdo do 1º ficheiro para o 2º, trocando todos os ‘a’ por ‘*’ e os ‘o’ por ‘_’.
//

typedef struct {
    int aluno;
    int teste1;
    int teste2;
    int TP;
}aluno;

int64_t fileSize(char *dir){
    int64_t fileSize = 0;
    FILE *filePointer = fopen(dir, "r");
    if(filePointer == NULL) return -1;
    fseek(filePointer, 0, SEEK_END);
    fileSize = ftell(filePointer);
    fclose(filePointer);
    return fileSize;
}

int readFile(char *dir, char *returnFileData){
    FILE *filePointer = fopen(dir, "r");
    if(filePointer == NULL) return -1;
    for(int64_t i = 0 ; i < strlen(returnFileData) ; i++){
        fseek(filePointer, i, SEEK_SET);
        returnFileData[i] = fgetc(filePointer);
    }
    fclose(filePointer);
    return 1;
}

int main(){
    char dir[] = {"alunosCatalogo.txt"};
    int64_t fsize = 0;
    aluno alunos[2048];
    char buffer[1024] = {'\0'};
    char empty[1024] = {' '};
    int bufferlen = 0;
    int j = 0 ;
    int k = 0 ;
    int J = 0 ;
    int alunosAprovados = 0;
    fsize = fileSize(dir);
    if(fsize == -1) {
        fputs("Ficheiro CatalogoAluno Nao Existe\n",stdout);
        return 0;
    }
    if(fsize == 0) {
        fputs("Ficheiro CatalogoAluno Vazio\n",stdout);
        return 0;
    }
    char *data = malloc(sizeof(char)*fsize);
    if(readFile(dir, data) == -1){
        fputs("An Error Has Occured\n",stdout);
        return 1;
    }
    for(int64_t i = 0 ; i < fsize ; i++){
        isasciinum(data[i]){
            buffer[k] = data[i];
            k++;
            continue;
        }
        if(J == 0){
            alunos[j].aluno = atoi(buffer);
        }
        if(J == 1){
            alunos[j].teste1 = atoi(buffer);
        }
        if(J == 2){
            alunos[j].teste2 = atoi(buffer);
        }
        if(J == 3){
            alunos[j].TP = atoi(buffer);
        }
        bufferlen = strlen(buffer);
        for(int wtv = 0 ; wtv < bufferlen ; wtv++){
            buffer[wtv] = '\0';
        }
        k = 0;
        J++;
        if(data[i] == '\n'){
            J = 0;
            j++;
        }
    }
    for(int i = 0 ; i < j ; i++){
        //printf("Aluno %i\n", alunos[i].aluno);
        //printf("teste1: %.2f\t",alunos[i].teste1*0.25);
        //printf("teste2: %.2f\t",alunos[i].teste2*0.25);
        //printf("TP: %.2f\n",alunos[i].TP*0.5);
        if(((alunos[i].teste1*0.25) + (alunos[i].teste2*0.25) + (alunos[i].TP*0.5)) >= 10 ){
            alunosAprovados++;
        }
    }
    printf("\n%i Alunos Tiveram Nota Final Positiva\n", alunosAprovados);
}
