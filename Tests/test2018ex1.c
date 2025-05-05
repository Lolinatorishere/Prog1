//1. Suponha que no array de caracteres canoistas[250][100], declarado local à função main,
//estão armazenados os nomes dos canoístas inscritos na FPC (Federação Portuguesa de
//Canoagem) no ano 2018.
//a. Implemente a função writeCanoistas(…) que escreve para o ficheiro de texto
//canoistas2018.txt os nomes dos canoistas (um em cada linha) armazenados no
//array canoistas.
//b. Implemente a função ordenaCanoistas (…) que, coloca os nomes dos canoístas
//ordenados por ordem alfabética.
//


//a):
int writeCanoistas(char **input, int totalCanoistas){
    FILE *fp = fopen("canoistas2018.txt", "w");
    if(fp == NULL)return -1;
    for(int i = 0 ; i < totalCanoistas, i++){
        fprintf(fp,"%s\n", *input[i]);
    }
    fclose(fp);
    return 0;
}

//b):
int ordenaCanoistas(char **input, int totalCanoistas){
    int step = 0;
    for (int i = 0 ; i < totalCanoistas-1 ; i++){
        for(step = 0 ; step < totalCanoistas-i-1; step++){
            if(strcmp(input[step]), input[step+1])> 0){
                char temp[100];
                strcpy(temp, input[step+1]);
                strcpy(input[step+1], input[step]);
                strcpy(input[step], temp);
            }
        }
    }
}

