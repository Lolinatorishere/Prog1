#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/time.h>
#include <time.h>
#define isasciinum(STRING)\
    if(STRING >= 48 && STRING <= 57)

//Folha exercícios 2 - Ficheiros binários
//Pretende-se implementar um programa para gerir a informação sobre os participantes no
//workshop sobre Transformação Digital.
//Sobre cada participante deve-se armazenar o nome, valor pago na inscrição e Tipo de participante
//(E-Empresa, A-Aluno, C-Convidado, O-Outro).
//As inscrições estão abertas durante 15 dias.
//O máximo número de participantes é de 150.
//A informação deve ser armazenada no ficheiro binário
//“TranfDigital2025.dat”
//
//O programa deverá permitir:
//1. Receber informação sobre um participante: O programa deverá pedir ao
//utilizador os dados do participante e acrescentá-los aos dados já armazenados.
//Os participantes são numerados sequencialmente à medida que são
//introduzidos no sistema.
//2. Listar informação: O programa deverá permitir listar informação sobre todos
//os participantes inscritos.
//3. Listar um participante: O programa deverá permitir listar a informação sobre um
//participante (dado o número de inscrição).
//4. Soma pagamentos: O programa deverá permitir calcular o somatório dos valores
//pagos por todos os participantes.
//5. Listar por tipo de participante: O programa deverá permitir saber quantos dos
//participantes são de um determinado tipo de participante (por ex. aluno).
//6. Escrever informação para ficheiro texto: O programa deverá permitir escrever
//para o ficheiro de texto “TD2025_Inscritos.txt” o número e nome de todos os
//participantes (um participante em cada linha).
//7. Alterar informação: O programa deverá permitir alterar o valor pago por um
//determinado participante (dado o número de inscrição).

//Sobre cada participante deve-se armazenar o nome, valor pago na inscrição e Tipo de participante
//(E-Empresa, A-Aluno, C-Convidado, O-Outro).
//As inscrições estão abertas durante 15 dias.
//O máximo número de participantes é de 150.
//A informação deve ser armazenada no ficheiro binário

typedef struct{
    char name[256];
    double payment;
    char type;
    int participantNum;
}participant;

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

int writeFile(char *dir, char *fileData){
    int i = 0;
    FILE *filePointer = fopen(dir, "w");
    fseek(filePointer, 0, SEEK_END);
    while(fileData[i] != '\0'){
        fprintf(filePointer, "%c", fileData[i]);
        i++;
    }
    fclose(filePointer);
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

//1. Receber informação sobre um participante: O programa deverá pedir ao
//utilizador os dados do participante e acrescentá-los aos dados já armazenados.
//Os participantes são numerados sequencialmente à medida que são
//introduzidos no sistema.
//2. Listar informação: O programa deverá permitir listar informação sobre todos
//os participantes inscritos.
//3. Listar um participante: O programa deverá permitir listar a informação sobre um
//participante (dado o número de inscrição).
//4. Soma pagamentos: O programa deverá permitir calcular o somatório dos valores
//pagos por todos os participantes.
//5. Listar por tipo de participante: O programa deverá permitir saber quantos dos
//participantes são de um determinado tipo de participante (por ex. aluno).
//6. Escrever informação para ficheiro texto: O programa deverá permitir escrever
//para o ficheiro de texto “TD2025_Inscritos.txt” o número e nome de todos os
//participantes (um participante em cada linha).
//7. Alterar informação: O programa deverá permitir alterar o valor pago por um
//determinado participante (dado o número de inscrição).

int main(){
    struct timeval tv;
    struct timezone tz;
    tz.tz_minuteswest = 0;
    tz.tz_dsttime = 0;
    gettimeofday(&tv,&tz);
    printf("%ld",tv.tv_sec);
    char buffer[1024];
    int menuState = 0;
    int state = 0;
    participant participants[150];
    while(state == 0){

        system("clear");//doesnt work on widnoes
        if(menuState == 0){
            printf("Transformacao Digital\n\n");
            printf("Para sair prima 0\n");
            printf("Para novo participante prima 1\n");
            printf("Para ver todos participantes prima 2\n");
            printf("Para ver valores totais prima 3\n");
            printf("Para ver um participante 4\n");
            printf("Para editar inscricao prima 5\n");
            printf("Para descaregar para ficheiro prima 6\n");
            fgets(buffer, 253, stdin);
            if(sanitiseInputNonInts(buffer) == -1){
                printf("Input Invalido insira somente numeros");
                continue;
            }
            if(atoi(buffer) < 0 || atoi(buffer) > 7){
                printf("Input Invalido insira uma das opcoes validas\n");
                continue;
            }
            menuState = atoi(buffer);
            if(menuState == 0) break;
        }
        if(menuState == 1){
           // printf("Para Sair Completa os inputs ou escreve 'FIM' para sair sem guardar Dados\n");
           // printf("Inserir Nome:");
           // fgets(buffer,253, stdin);
           // sanitiseNewLines(buffer);
           // if(buffer[0] == 'F'&&buffer[1] == 'I'&&buffer[2] == 'M'){
           //     menuState = 0;
           //     continue;
           // }
           // strcpy(input.name,buffer);
           // printf("Inserir numero TLM:");
           // fgets(buffer,253, stdin);
           // sanitiseNewLines(buffer);
           // if(buffer[0] == 'F'&&buffer[1] == 'I'&&buffer[2] == 'M'){
           //     menuState = 0;
           //     continue;
           // }
           // strcpy(input.phonenum,buffer);
           // printf("Inserir Proviniencia:");
           // fgets(buffer,253, stdin);
           // sanitiseNewLines(buffer);
           // if(buffer[0] == 'F'&&buffer[1] == 'I'&&buffer[2] == 'M'){
                menuState = 0;
           //     continue;
           // }
           // strcpy(input.provenient,buffer);
           // input.id = id+=1;
           // char *inscription = malloc(sizeof(char)*1024);
           // sprintf(inscription,"%i;",input.id);
           // strcat(inscription, input.name);
           // strcat(inscription, ";");
           // strcat(inscription, input.phonenum);
           // strcat(inscription, ";");
           // strcat(inscription, input.provenient);
           // strcat(inscription, "\n");
           // writeFile(dir,inscription);
           // free(inscription);
        }
        if(menuState == 2){
            system("clear");
            //free(fileData);
            //fsize = fileSize(dir);
            //fileData = malloc(sizeof(char)*fsize);
            //readFile(dir, fileData, fsize);
            //printf("%s",fileData);
            //printf("\npara sair imprima qualquer falor\n");
            //fgets(buffer,253, stdin);
            menuState = 0;
        }
        if(menuState == 3){
           // int selectedID = 0;
           // system("clear");
           // free(fileData);
           // fsize = fileSize(dir);
           // fileData = malloc(sizeof(char)*fsize);
           // readFile(dir, fileData, fsize);
           // id = idTotal(fileData, fsize);
           // printf("Inserir ID:");
           // fgets(buffer,253, stdin);
           // if(sanitiseInputNonInts(buffer) == -1){
           //     printf("Instera um numero valido\n");
           //     continue;
           // }
           // if(atoi(buffer) == 0 || atoi(buffer) > id){
           //     printf("ID invalido nao existe no sistema");
           //     continue;
           // }
           // selectedID = atoi(buffer);
           // printf("Inserir Nome:");
           // fgets(buffer,253, stdin);
           // sanitiseNewLines(buffer);
           // if(buffer[0] == 'F'&&buffer[1] == 'I'&&buffer[2] == 'M'){
           //     menuState = 0;
           //     continue;
           // }
           // strcpy(input.name,buffer);
           // printf("Inserir numero TLM:");
           // fgets(buffer,253, stdin);
           // sanitiseNewLines(buffer);
           // if(buffer[0] == 'F'&&buffer[1] == 'I'&&buffer[2] == 'M'){
           //     menuState = 0;
           //     continue;
           // }
           // strcpy(input.phonenum,buffer);
           // printf("Inserir Proviniencia:");
           // fgets(buffer,253, stdin);
           // sanitiseNewLines(buffer);
           // if(buffer[0] == 'F'&&buffer[1] == 'I'&&buffer[2] == 'M'){
           //     menuState = 0;
           //     continue;
           // }
           // strcpy(input.provenient,buffer);
           // input.id = selectedID;
           // char *inscription = malloc(sizeof(char)*1024);
           // sprintf(inscription,"%i;",input.id);
           // strcat(inscription, input.name);
           // strcat(inscription, ";");
           // strcat(inscription, input.phonenum);
           // strcat(inscription, ";");
           // strcat(inscription, input.provenient);
           // updateFile(selectedID,inscription,fsize,fileData,dir);
           // free(inscription);
           menuState = 0;
        }
    }
}
