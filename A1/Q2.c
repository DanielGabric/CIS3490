/*Name: Daniel Gabric
  ID: ******
  Assignment #1 Q2
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void getFact(int * n2, long double X);
long double f(long double X,long double x);
long double fP(long double X);
void newton(long double X, long double * n1);

/*Has to be compiled with the -lm flag*/

int main()
{
    /*Change this value for different n1 and n2 values*/
    long double X=8.345345e+36;
    long double n1 = 10;
    int n2 = 1;

    getFact(&n2,X);
    newton(X,&n1);

    printf("n1 = %Lf\nn2 = %d\n",n1,n2);
    return 0;
}

void getFact(int * n2,long double X){
    while(X>(*n2)){
        X/=((*n2)++);
    }
}

void newton(long double X, long double * n1){
    while(ceil(f(*n1,X)+X)!=X){
        *n1 = *n1 - f(*n1,X)/fP(*n1);
    }
}

/*f(x)*/
long double f(long double X, long double x){
    return X*log2(X)-x;
}

/*f'(x)*/
long double fP(long double X){
    return log(X)/log(2.0)+1/log(2.0);

}
