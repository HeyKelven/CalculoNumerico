#include "lib.h"

void verifing(int argc, char **argv){

    //Se não tiver os três parametros (fora o próprio n2m) a exdcução para.
    if(argc != 4)
        exit(1);

    //Separa os argumentos para cada variavel, para tornar mais fácil demanipular a informação.
    int basenow = atoi(argv[2]), baseaf = atoi(argv[3]);

    //Caso a base que informa base atual do numero esteja fora do range premitido.
    if(basenow >= 37 || basenow <= 1)  
        exit(1);
    
    ///Caso a base que informa base desejada do numero esteja fora do range premitido.
    if(baseaf >= 37 || baseaf <= 1)
        exit(1);
}

unsigned long int potency(int num, int q){
    if(q == 0)
        return 1;
    else {
        unsigned long int res = num;
        --q;
        for( ; q > 0; q--){
            res *= num;
            if (res > 4294967296)
                exit(1);
        }
        return res;
    }
}

//Verifica se algum caractere do numero passado está em disacordo com a base passa atual. 
unsigned long int toBase10(char* number,int basenow){
    int i, aux;
    unsigned long int soma = 0;
    for (i = 0; i < (int) strlen(number); i++){
        aux = toupper(number[i]); 
        if(aux < 48 || (aux > 57 && aux < 65) || aux > 90)
            exit(1); 
        if (number[i] > 57)
            aux -= 55;
        else
            aux -= 48;
        if (aux >= basenow)
            exit(1);
        //soma += aux * (long int)(pow(basenow, strlen(number) - (1 + i)));
        soma += aux * potency(basenow, strlen(number) - (1 + i));
        if(soma > potency(2,32))
            exit(1);
    } 
    return soma;
}

char *toAnyBase(unsigned long int number,int casas, int baseaf){

    int aux = 0, i;
    //Aqui é criada uma variavel com o valor de i que ao termino do processo receberá a resposta.
    char *newnumber = malloc (casas * sizeof (char));
    char *invertnumber = malloc (casas * sizeof (char));
    char maisnumber[2];

    //Aqui é feito as contas com divisoes para saber qual numero corresponde na outra base.    
    if (number == 0){
        newnumber[0] = '0';
        newnumber[1] = '\0';
        return newnumber;
    }
    maisnumber[1] = '\0';
    
    for (i = 0; number != 0; i++){
        aux = number % baseaf;
        if (aux > 9){
            maisnumber[0] = (aux + 55);
            maisnumber[1] = '\0';
        } else {
            maisnumber[0] = (aux + 48);        
            maisnumber[1] = '\0';
        }
        number /= baseaf;
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

    return invertnumber;
}

//É preciso saber quantas casas tem a soma anterior, porém não podemos perder 
//a variavel soma, então somente copiamos ela.
int casasDec (unsigned long int number){
    int i = 1;
    while(number != 0){
        number /= 10;
        i++;
    }
    return i;
}

void newBase(int argc, char **argv){

    verifing(argc, argv);

    unsigned long int soma = toBase10(argv[1], atoi(argv[2]));

    printf("%s\n",toAnyBase(soma,casasDec(soma),atoi(argv[3])));

    exit(0);
}