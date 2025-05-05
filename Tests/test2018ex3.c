//Considere a sequência Seq definida pela seguinte relação de recorrência:
//seq(n) =
//{
//0, if n <= 0
//4n³ + seq(n-1), if n > 0
//}
//Implemente, recorrendo ao uso de recursividade, a função computSeq(...) que calcula e
//retorna o enésimo número da sequência.
//
int computSeq(int n){
    if(n <= 0)return 0;
    return computSeq(n-1) + (4*(n*n*n));
}


