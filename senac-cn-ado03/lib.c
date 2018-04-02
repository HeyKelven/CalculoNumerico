#include "lib.h"

void scaryerror(){
    
    float x_flt;
    double x_dbl;
    long double x_ldbl;

    FILE* e_flt = popen("gnuplot -persistent","w");
    FILE* e_dbl = popen("gnuplot -persistent","w");
    FILE* e_ldbl = popen("gnuplot -persistent","w");

    fprintf(e_flt, "set terminal png\n");
    fprintf(e_flt, "set output 'euler_flt.png'\n");
    fprintf(e_flt,"set logscale x\n");
    fprintf(e_flt, "set title 'Euler in Float'\n");
    fprintf(e_flt, "set xlabel 'x'\n");
    fprintf(e_flt, "set ylabel 'f(x)'\n");
    fprintf(e_flt, "set nokey\n");
    fprintf(e_flt, "set tic scale 0\n");
    fprintf(e_flt, "set yrange [0:3.5]\n");
    fprintf(e_flt, "plot '-' w l\n");

    fprintf(e_dbl, "set terminal png\n");
    fprintf(e_dbl, "set output 'euler_dbl.png'\n");
    fprintf(e_dbl,"set logscale x\n");
    fprintf(e_dbl, "set title 'Euler in Double'\n");
    fprintf(e_dbl, "set xlabel 'x'\n");
    fprintf(e_dbl, "set ylabel 'f(x)'\n");
    fprintf(e_dbl, "set nokey\n");
    fprintf(e_dbl, "set tic scale 0\n");
    fprintf(e_dbl, "set yrange [0:3.5]\n");
    fprintf(e_dbl, "plot '-' w l\n");

    fprintf(e_ldbl, "set terminal png\n");
    fprintf(e_ldbl, "set output 'euler_ldbl.png'\n");
    fprintf(e_ldbl,"set logscale x\n");
    fprintf(e_ldbl, "set title 'Euler in Long Double'\n");
    fprintf(e_ldbl, "set xlabel 'x'\n");
    fprintf(e_ldbl, "set ylabel 'f(x)'\n");
    fprintf(e_ldbl, "set nokey\n");
    fprintf(e_ldbl, "set tic scale 0\n");
    fprintf(e_ldbl, "set yrange [0:3.5]\n");
    fprintf(e_ldbl, "plot '-' w l\n");

    for(x_flt = 1.0; x_flt <= 10e+20; x_flt *= 10)
        fprintf(e_flt,"%f %f\n", x_flt, powf(1+1/x_flt,x_flt));

    for(x_dbl = 1.0; x_dbl <= 10e+20; x_dbl *= 10)
        fprintf(e_dbl,"%lf %lf\n", x_dbl, pow(1+1/x_dbl,x_dbl));

    for(x_ldbl = 1.0; x_ldbl <= 10e+20; x_ldbl *= 10)
        fprintf(e_ldbl,"%Lf %Lf\n", x_ldbl, powl(1+1/x_ldbl,x_ldbl));

    fprintf(e_flt,"e\n");
    fprintf(e_dbl,"e\n");
    fprintf(e_ldbl,"e\n");

    pclose(e_flt);
    pclose(e_dbl);
    pclose(e_ldbl);
}