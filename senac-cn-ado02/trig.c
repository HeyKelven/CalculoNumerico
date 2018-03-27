#include"lib.h"

int main(void){

for (int i = 0; i<= 720; i++){

    printf("Cossenos: %lf\t",f_cos(chanToRad(i)));
    printf("%lf\t\t",cos(chanToRad(i)));

    printf("Senos: %lf\t",f_sen(chanToRad(i)));
    printf("%lf\n",sin(chanToRad(i)));
}
}