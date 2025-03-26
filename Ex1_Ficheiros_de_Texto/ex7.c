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
    char id;
    char name[256];
    char phonenum[256];
    char provenient[256];
}entree;

int64_t fileSize(char *dir){
    int64_t fileSize = 0;
    FILE *filePointer = fopen(dir, "r");
    if(filePointer == NULL) return -1;
    fseek(filePointer, 0, SEEK_END);
    fileSize = ftell(filePointer);
    fclose(filePointer);
    return fileSize;
}

int readFile(char *dir, char *returnFileData, int64_t fileSize){
    FILE *filePointer = fopen(dir, "r");
    if(filePointer == NULL) return -1;
    for(int64_t i = 0 ; i < fileSize ; i++){
        fseek(filePointer, i, SEEK_SET);
        returnFileData[i] = fgetc(filePointer);
    }
    fclose(filePointer);
    return 1;
}

int sanitiseInputNonInts(char *input){
    char buffer[1024] = {'\0'};
    int j = 0;
    for (int i = 0 ; i < strlen(input) ; i++){
        isasciinum(input[i]){
            buffer[j] = input[i];
            j++;
        }
    }
    if(buffer[0] == '\0') return -1;
    strcpy(input,buffer);
}

int sanitiseNewLines(char *input){
    char buffer[1024] = {'\0'};
    int j = 0;
    for (int i = 0 ; i < strlen(input) ; i++){
        if(input[i]=='\n'){
            input[i] = '\0';
        }
    }
    if(buffer[0] == '\0') return -1;
    strcpy(input,buffer);
}

int writeFile(char *dir, char *fileData){
    int i = 0;
    FILE *filePointer = fopen(dir, "a");
    fseek(filePointer, 0, SEEK_END);
    while(fileData[i] != '\0'){
        fprintf(filePointer, "%c", fileData[i]);
        i++;
    }
    fclose(filePointer);
}

int idTotal(char *data, int64_t fsize){
    int lines = -1;
    for(int64_t i = 0 ; i < fsize ; i++){
        if(data[i] == '\n')lines++;
    }
    return lines;
}

int updateFile(int id,char *updateData, int64_t fsize, char *fileData, char *dir){
    int64_t filesize = fsize + strlen(updateData);
    char *newData = malloc(sizeof(char)*filesize*2);
    int lines = 0;
    int skip = 0;
    int64_t lastline = 0;
    int64_t endline = 0;
    int64_t j = 0;
    for(int64_t i = 0 ; i < filesize; i++){
        if(fileData[i] =='\n'){
            lines++;
        };
        if(lines == id && lastline == 0){
            lastline = i;
        }
        if(lines == id+1 && endline == 0){
            endline = i;
        }
    }
    for(int64_t i = 0 ; i <= lastline ; i++){
        newData[i] = fileData[i];
    }
    j = lastline+1;
    for(int i = 0 ; i < strlen(updateData) ; i++){
        newData[j] = updateData[i];
        j++;
    }
    for(int64_t i = endline; i < fsize  ; i++){
        newData[j] = fileData[i];
        j++;
    }
    FILE *filePointer = fopen(dir,"w");
    fprintf(filePointer,"%s",newData);
    free (newData);
    fclose(filePointer);
}

int main(){
    char dir[] = "cimeiraIPVC2025.txt";
    entree input;
    char buffer[254];
    int state = 0;
    int id = 0;
    int menuState = 0;
    int64_t fsize = 0;
    char *fileData = malloc(sizeof(char)*1);
    fsize = fileSize(dir);
    if(fsize == -1){
        writeFile(dir,"cimeiraIPVC2025 inscricoes\n");
    }else{
        //note: Malloc doesnt just go haha negative number ignore malloc
        //it sigsevs the program
        fileData = malloc(sizeof(char)*fsize);
        readFile(dir, fileData, fsize);
        id = idTotal(fileData, fsize);
    }
    while(state == 0){
        system("clear");//doesnt work on widnoes
        if(menuState == 0){
            printf("Cimeira IPVC 2025 Inscricoes\n\n");
            printf("Para sair prima 0\n");
            printf("Para nova Inscricao prima 1\n");
            printf("Para ver inscricoes prima 2\n");
            printf("Para editar inscricao prima 3\n");
            fgets(buffer, 253, stdin);
            if(sanitiseInputNonInts(buffer) == -1){
                printf("Input Invalido insira somente numeros");
                continue;
            }
            if(atoi(buffer) < 0 || atoi(buffer) > 3){
                printf("Input Invalido insira uma das opcoes validas\n");
                continue;
            }
            menuState = atoi(buffer);
            if(menuState == 0) break;
        }
        if(menuState == 1){
            printf("Para Sair Completa os inputs ou escreve 'FIM' para sair sem guardar Dados\n");
            printf("Inserir Nome:");
            fgets(buffer,253, stdin);
            sanitiseNewLines(buffer);
            if(buffer[0] == 'F'&&buffer[1] == 'I'&&buffer[2] == 'M'){
                menuState = 0;
                continue;
            }
            strcpy(input.name,buffer);
            printf("Inserir numero TLM:");
            fgets(buffer,253, stdin);
            sanitiseNewLines(buffer);
            if(buffer[0] == 'F'&&buffer[1] == 'I'&&buffer[2] == 'M'){
                menuState = 0;
                continue;
            }
            strcpy(input.phonenum,buffer);
            printf("Inserir Proviniencia:");
            fgets(buffer,253, stdin);
            sanitiseNewLines(buffer);
            if(buffer[0] == 'F'&&buffer[1] == 'I'&&buffer[2] == 'M'){
                menuState = 0;
                continue;
            }
            strcpy(input.provenient,buffer);
            input.id = id+=1;
            char *inscription = malloc(sizeof(char)*1024);
            sprintf(inscription,"%i;",input.id);
            strcat(inscription, input.name);
            strcat(inscription, ";");
            strcat(inscription, input.phonenum);
            strcat(inscription, ";");
            strcat(inscription, input.provenient);
            strcat(inscription, "\n");
            writeFile(dir,inscription);
            free(inscription);
        }
        if(menuState == 2){
            system("clear");
            free(fileData);
            fsize = fileSize(dir);
            fileData = malloc(sizeof(char)*fsize);
            readFile(dir, fileData, fsize);
            printf("%s",fileData);
            printf("\npara sair imprima qualquer falor\n");
            fgets(buffer,253, stdin);
            menuState = 0;
        }
        if(menuState == 3){
            int selectedID = 0;
            system("clear");
            free(fileData);
            fsize = fileSize(dir);
            fileData = malloc(sizeof(char)*fsize);
            readFile(dir, fileData, fsize);
            id = idTotal(fileData, fsize);
            printf("Inserir ID:");
            fgets(buffer,253, stdin);
            if(sanitiseInputNonInts(buffer) == -1){
                printf("Instera um numero valido\n");
                continue;
            }
            if(atoi(buffer) == 0 || atoi(buffer) > id){
                printf("ID invalido nao existe no sistema");
                continue;
            }
            selectedID = atoi(buffer);
            printf("Inserir Nome:");
            fgets(buffer,253, stdin);
            sanitiseNewLines(buffer);
            if(buffer[0] == 'F'&&buffer[1] == 'I'&&buffer[2] == 'M'){
                menuState = 0;
                continue;
            }
            strcpy(input.name,buffer);
            printf("Inserir numero TLM:");
            fgets(buffer,253, stdin);
            sanitiseNewLines(buffer);
            if(buffer[0] == 'F'&&buffer[1] == 'I'&&buffer[2] == 'M'){
                menuState = 0;
                continue;
            }
            strcpy(input.phonenum,buffer);
            printf("Inserir Proviniencia:");
            fgets(buffer,253, stdin);
            sanitiseNewLines(buffer);
            if(buffer[0] == 'F'&&buffer[1] == 'I'&&buffer[2] == 'M'){
                menuState = 0;
                continue;
            }
            strcpy(input.provenient,buffer);
            input.id = selectedID;
            char *inscription = malloc(sizeof(char)*1024);
            sprintf(inscription,"%i;",input.id);
            strcat(inscription, input.name);
            strcat(inscription, ";");
            strcat(inscription, input.phonenum);
            strcat(inscription, ";");
            strcat(inscription, input.provenient);
            updateFile(selectedID,inscription,fsize,fileData,dir);
            free(inscription);
            menuState = 0;
        }
    }
    free(fileData);
    return 0;
}
