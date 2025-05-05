//4. Suponha que se pretende fazer a gestão das compras efetuadas numa loja de pronto a
//vestir. As compras são numeradas sequencialmente pelo programa. Assim, sobre cada
//compra é necessário armazenar, o numero, nome do cliente, o montante pago e o tipo de
//pagamento (D- dinheiro, M- multibanco, etc.). A informação deve ser armazenada numa
//lista ligada simples.
//
//a. Defina uma estrutura de dados que represente a lista ligada. Defina a lista local à
//função main().
//
//b. Tendo por base a estrutura de dados definida na alínea anterior, implemente a
//função getMediaPagDinheiro(…) que deverá calcular e devolver o valor médio
//dos montantes pagos em dinheiro (tipo de pagamento D).
//

//a):

typedef struct compra{
    int numero;
    char nome[256];
    double montante;
    char tipo;
    compra *next;
}COMPRA;

//b):

double getMediaPagDinheiro(COMPRA *input){
    double total = 0;
    int type_total=0;
    if(input->next == NULL){
        if(input->tipo == 'D')return input->montante;
    }
    while(1){
        if(input->tipo == 'D'){
            type_total += 1;
            total += input->montante;
        }
        if(input->next == NULL)break;
        input = input->next;
    }
    return total/type_total;
}
