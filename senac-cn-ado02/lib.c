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

double f_sin(double i){
    double soma = 0;
    i = chanToRad(i);

    for(int n = 0; n <= 25; n++){
        soma += (pow(-1,n)/denominador(2*n + 1))*pow(i,2*n + 1);
    }
    return soma;
}

double f_cos(double i){
    double soma = 0;
    i = chanToRad(i);

    for(int n = 0; n <= 25; n++){
        soma += (pow(-1,n)/denominador(2*n))*pow(i,2*n);
    }
    return soma;
}

double relative_error_sin(double i){

    double x = sin(chanToRad(i)), y = f_sin(chanToRad(i));
    double res = (((x - y) * 100) / x);
    return res > 0 ? res : res * (-1);
}

double absolut_error_sin(double i){
    
    double res = sin(chanToRad(i)) - f_sin(chanToRad(i));
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

void putFile(){

    FILE *sin_dat = fopen("seno.dat","w"), *cos_dat = fopen("cosseno.dat","w");
    FILE *sin_plot = popen("gnuplot -persistent","w"), *cos_plot = popen("gnuplot -persistent","w");

    fprintf(sin_plot, "set terminal png\n");
    fprintf(sin_plot, "set output 'seno.png'\n");
    fprintf(sin_plot, "set title 'SIN (0 <= x <= 4 pi)'\n");
    fprintf(sin_plot, "set xlabel 'radianos'\n");
    fprintf(sin_plot, "set ylabel 'SIN(x)'\n");
    fprintf(sin_plot, "set tic scale 0\n");
    fprintf(sin_plot, "set nokey\n");

    fprintf(cos_plot, "set terminal png \n");
    fprintf(cos_plot, "set output 'cosseno.png' \n");
    fprintf(cos_plot, "set title 'COS (0 <= x <= 4 pi)'\n");
    fprintf(cos_plot, "set xlabel 'radianos'\n");
    fprintf(cos_plot, "set ylabel 'COS(x)'\n");
    fprintf(cos_plot, "set tic scale 0\n");
    fprintf(cos_plot, "set nokey\n");

    fprintf(sin_plot,"plot '-' \n");
    fprintf(cos_plot,"plot '-' \n");

    for (int x = 0; x <= 720; x++){
        fprintf(sin_dat,"%d\t%.7lf\t%lf\t%lf\n", x, f_sin(x), absolut_error_sin(x), relative_error_sin(x));
        fprintf(cos_dat,"%d\t%.7lf\t%lf\t%lf\n", x, f_cos(x), absolut_error_cos(x), relative_error_cos(x));

        fprintf(sin_plot, "%lf %lf\n", chanToRad(x), f_sin(x));
        fprintf(cos_plot, "%lf %lf\n", chanToRad(x), f_cos(x));
    }

    fclose(sin_plot);
    fclose(cos_plot);
    pclose(sin_dat);
    pclose(cos_dat);

    exit(0);

}