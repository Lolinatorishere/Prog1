//Suponha que o excerto de código em baixo faz parte de um programa, implementado na
//linguagem C, para fazer a gestão dos participantes numa BikeTour pelo distrito de Viana
//do Castelo.
//
//typedef struct ciclista{
//int n_inscricao, nCC;
//char nome[100], email[50];
//} CICLISTA;
//….
//int main( ) {
//CICLISTA ciclistas[600]; int tot_insc=0 ;
//….
//}
//
//Tendo por base a estrutura de dados acima definida e sabendo que a variável tot_insc
//armazena o número total de inscrito (numero de registos carregados no array ciclistas):
//a. Implemente a função gravaCiclistas(…) que escreva para o ficheiro binário
//“ciclistas2018.dat” toda a informação armazenada no array ciclistas.
//
//b. Pretende-se alterar o programa e substituir a definição estática do array ciclistas
//pela alocação dinâmica de memória. Escreva o excerto do programa que peça ao
//utilizador o número de ciclistas e reserve o espaço de memória estritamente
//necessário para armazenar a informação. Nota: a memória deve ser libertada
//imediatamente antes do programa terminar.
//
//c. Suponha que o array ciclistas se encontra ordenado por ordem crescente do
//numero de inscrição (campo n_inscricao). O excerto de código em baixo faz
//parte da implementação do algoritmo de pesquisa binária e pretende retornar o
//índice do array onde o numero, recebido como parâmetro na função (parâmetro
//num), se encontra. Complete o código da função.
//
//int pesquisaBinNum( … , … , int num ) {
//int meio=0, ini=0, fim= … ;
//…….
//}
//

//a):

int gravaCilclistas(CICLISTA *input, int tot_insc){
    FILE *fp = fopen("ciclistas2018.dat", "wb");
    if(fp == NULL)return -1;
    for (int i = 0 ; i < tot_insc ; i++){
        fwrite(input[i], sizeof(CICLISTA), tot_insc, fp);
    }
    fclose(fp);
    return 0;
}

//b):

//... codigo antes
int tot_insc = 0;
char buffer[256] = {'\0'};
printf("Insira o numero total de ciclistas");
fgets(buffer,256,stdin);
tot_insc = atoi(buffer);
if(tot_insc <= 0)return -1;
CICLISTA *ciclistas = (CICLISTA)malloc(sizeof(CICLISTA)*tot_insc);
//... resto do codigo
free(ciclistas);
return 0;
}
//... fim do codigo

//c):

int pesquisaBinNum(CICLISTA *input,int tot_insc, int num){
    int meio = 0, ini = 0, fim = tot_insc;
    meio = (tot_insc-1)/2;
    while(ini <= fim){
        if(num == input[meio]) return meio;
        if(num > input[meio] ) ini = meio+1;
        if(num < input[meio] ) fim = meio-1;
    }
    return -1
}

