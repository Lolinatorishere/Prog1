//Com base na seguinte fórmula
//∑ (from i=1 to n) 3i²

//a. Escreva a função computeSum(int n), que recorrendo ao uso de recursividade,
//calcula e retorna o valor do somatório apresentado.
//
//b. Implemente a mesma função sem recorrer ao uso de recursividade.
//
//c. Comente a afirmação “Devem-se usar funções recursivas sempre que for possí-
//vel”.

//a):

int computeSum(int n){
    if(n <= 1){
        return 3;
    }else{
        return computeSum(n - 1) + (3 *(n*n));
    }
}

//b):
int computeSum(int n){
    int total = 0;
    while(n > 1){
        total += (3*(n*n));
        n--;
    }
    total += 3;
    return total;
}

//c):
/*
Funcoes recursivas nao deviam ser sempre usadas quando possivel pois sao muito intensivas em relacao a memoria
em situacoes em que esta e limitada usar uma funcao que limita a utilizacao da memoria a custo de aumentar a complexidade
do codigo e preferivel.
*/

