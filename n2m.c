#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]){

    //Se não tiver os três parametros (fora o próprio n2m) a exdcução para.
    if(argc != 4)
        exit(1);

    //Separa os argumentos para cada variavel, para tornar mais fácil demanipular a informação.
    char *numero = argv[1];
    int basenow = atoi(argv[2]), baseaf = atoi(argv[3]);

    //Caso a base que informa base atual do numero esteja fora do range premitido.
    if(basenow >= 37 || basenow <= 1)  
        exit(1);
    
    ///Caso a base que informa base desejada do numero esteja fora do range premitido.
    if(baseaf >= 37 || baseaf <= 1)
        exit(1);

    //Verifica se algum caractere do numero passado está em disacordo com a base passa atual.
    int i, aux;
    unsigned long int soma = 0;
    for (i = 0; i < strlen(numero); i++){
        aux = toupper(numero[i]); 
        if(aux < 48 || aux > 57 && aux < 65 || aux > 90)
            exit(1); 
        if (numero[i] > 57)
            aux -= 55;
        else
            aux -= 48;
        if (aux >= basenow)
            exit(1);
        soma += aux * (long int)(pow(basenow, strlen(numero) - (1 + i)));
    }    

    printf("%ld\n", soma);

    //É preciso saber quantas casas tem a soma anterior, porém não podemos perder 
    //a variavel soma, então somente copiamos ela.
    i = 1;
    int rsoma = soma;
    while(rsoma != 0){
        rsoma /= baseaf;
        i++;
    }

    //Aqui é criada uma variavel com o valor de i que ao termino do processo receberá a resposta.
    char newnumber[i],invertnumber [i];
    char maisnumber[2];
    
    printf("%d\n",'-');

    //Aqui é feito as contas com divisoes para saber qual numero corresponde na outra base.
    aux = 0;
    //Quando 0(zero) o programa não retorna nenhum valor pq o soma já é zero
    //Aqui 
    maisnumber[1] = '\0';
    for (i = 0; soma != 0; i++){
        aux = soma % baseaf;
        if (aux > 9){
            maisnumber[0] = (aux + 55);
            maisnumber[1] = '\0';
        } else {
            maisnumber[0] = (aux + 48);        
            maisnumber[1] = '\0';
        }
        soma /= baseaf;
        if(i == 0)
            strcpy(newnumber,maisnumber);
        else
            strcat(newnumber,maisnumber);
    }

    //Ao fim do termino da instrução anterior, teremos um vetor de string com a resposta,
    //porém ela está invertida, agora basta inverter essa String.
    for (int j = 0; j <= i; j++)
        invertnumber[j] = newnumber[i - j - 1];
    invertnumber[i] = '\0';
    
    printf("%s\n", invertnumber);
    
    exit(0);
}