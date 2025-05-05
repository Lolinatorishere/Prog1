//1

#include <stdio.h>
#include <stdlib.h>

int main(){
    char nome[256];
    char pais[256];
    char idade[256];
    char buffer[256];
    FILE *fp = fopen("QSoft2017.txt", "a");
    while(1){
        printf("introduz nome:");
        fgets(nome, 256, stdin);
        printf("introduz pais:");
        fgets(pais, 256, stdin);
        printf("introduz idade:");
        fgets(idade, 256, stdin);
        fprintf(fp, "%s;%s;%s;\n", nome, pais, idade);
        printf("Deseja sair?\n");
        fgets(buffer, 256, stdin);
        if(buffer[0] == 'S'){
            fclose(fp);
            return 0;
        }
    }
}
