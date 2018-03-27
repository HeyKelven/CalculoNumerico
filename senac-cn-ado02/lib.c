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

double relative_error_sin(double i){

    double x = sin(chanToRad(i)), y = f_sen(chanToRad(i));
    double res = (((x - y) * 100) / x);
    return res > 0 ? res : res * (-1);
}

double absolut_error_sin(double i){
    
    double res = sin(chanToRad(i)) - f_sen(chanToRad(i));
    return res > 0 ? res : res * (-1);
}

double relative_error_cos(double i){
    
    double x = cos(chanToRad(i)), y = f_cos(chanToRad(i));
    double res = (((x - y) * 100) / x);
    return res > 0 ? res : res * (-1);
}

double absolut_error_cos(double i){
    
    double res = cos(chanToRad(i)) - f_cos(chanToRad(i));
    return res > 0 ? res : res * (-1);
}