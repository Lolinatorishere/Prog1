//#define MAX 3000
//typedef struct livro{
//int cod_livro, num_exemplares, ano;
//char ISBN [20], titulo[100], autores[6][100];
//} LIVRO;
//….
//int main( ) {
//LIVRO livros [MAX];
//….
//sortByIsbn(….)
//existeISBN(…)
//….
//}
//Tendo por base a estrutura de dados definida em cima:
//
//a. Implemente a função storeAllData(…) que escreve para o ficheiro binário “li-
//vros.dat” toda a informação armazenada no array livros.
//
//b. Implemente a função sortByIsbn(….) que ordena a informação do array livros por or-
//dem alfabética do ISBN.
//
//c. Implemente a função existeISBN(…) que verifica se o ISBN recebido como parâme-
//tro na função já existe no array livros. A função deverá retornar 1 caso já exista, caso
//contrário, deverá retornar 0.
//
//d. Referindo-se ao array livros, comente a seguinte afirmação: “O algoritmo de pesquisa
//binária apenas funciona se o array estiver ordenado pelo campo objeto da pesquisa”.
//

//a):
int storeAllData(LIVRO *input, int totalLivros){
    FILE *fp = fopen("livros.dat", "wb");
    if(fp == NULL) return -1;
    for (int i = 0 ; i < totalLivros ; i++){
        fwrite(totalLivros[i], sizeof(LIVRO), totalLivros, fp);
    }
    fclose(fp);
    return 0;
}

//b):
int sortByIsbn(LIVRO *input, int totalLivros){
    for (int step = 0 ; step < totalLivros ; step++){
        for(int i = 0 ; i = size - step-1 ; i++){
            if(strcmp(input[i].ISBN, input[i+1].ISBN) > 0){
                LIVRO temp = input[i+1];
                input[i+1] = input[i];
                input[i] = temp;
            }
        }
    }
}
 
//c):
int existeISBN(LIVRO *input, char *check, int totalLivros){
    for(int i = 0 ; i < totalLivros ; i++){
        if(strcmp(input[i].ISBN, check)==0){
            return 1;
        }
    }
    return 0;
}

//d):
/*
R: o algoritmo de pesquisa binaria so funciona se o array estiver ordenado pelo campo de pesquisa pois
o algoritmo nao verifica todos os valores antes ou depois do meio para reduzir no "search time" isto so funciona se:

1 os dados estao ordenados
2 o dado que se esta a pesquisar existe

se estivesemos a usar o algoritmo de pesquisa binaria num array nao ordenado de numeros por ex:
{ 0, 2 ,5, 3, 6}
e procurassemos pelo 3 o algoritmo nunca o iria encontrar pois mesmo que no array exista o numero nao esta ordenado
*/

