#include <stdio.h>
#include <stdlib.h>

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

int writeFile(char *dir, char *fileData){
    FILE *filePointer = fopen(dir, "w");
    fputs(fileData,filePointer);
    fclose(filePointer);
}

int main(){
    char dir[] = "curriculum.txt";
    char data[] = "Curso De Enginharia Informatica\nNumero:29730\tNome:Gabriel Banks\nCurso de CTeSP:TPSI com nota Final de 14.90\n";
    writeFile(dir, data);
    return 0;
}
