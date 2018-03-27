#include"lib.h"

double chanToRad(double i){
    return (i * M_PI / 180);
}

double denominador(int x){
    double res = 1;
    while(x > 1){
        res *= x;
        x--;
    }
    return res;
}


double f_sen(double i){
    double soma = 0;

    for(int n = 0; n <= 25; n++){
        soma += (pow(-1,n)/denominador(2*n + 1))*pow(i,2*n + 1);
    }
    return soma;
}

double f_cos(double i){
    double soma = 0;

    for(int n = 0; n <= 25; n++){
        soma += (pow(-1,n)/denominador(2*n))*pow(i,2*n);
    }
    return soma;
}