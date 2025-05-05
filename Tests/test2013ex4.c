//Escreva um programa, na linguagem C, que leia um número inteiro positivo n e n va-
//lores decimais e imprima para o ecrã a quantidade de valores que são inferiores à média
//dos valores lidos. O programa não deve impor limitações sobre o valor de n e deve reser-
//var a memória estritamente necessária.
//

//esta pergunta vai necessitar do realloc para poder funcionar direito;

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int total = 1;
    float *input = (float*)malloc(sizeof(float)*total);
    float average = 0;
    char buffer[256] = {'1'};
    while(atof(buffer) != 0){
        fgets(buffer, 256, stdin);
        if(atof(buffer)==0){
            continue;
        }
        input[total-1] = atof(buffer);
        average += atof(buffer);
        total++;
        input = realloc(input, sizeof(float)*total);
        if(input == NULL){
            free(input);
            return -1;
        }
    }
    average = average/total;
    for(int i = 0 ; i < total ; i++){
        if(input[i] < average){
            printf("%.2f e menor que a media dos valores inseridos\n", input[i]);
        }
    }
    free(input);
    return 0;
}
