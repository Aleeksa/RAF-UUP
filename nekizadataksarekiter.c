#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double rek(int n, int i, int k){
    //printf("n = %d , i = %d , k = %d \n",n,i,k);
    if(n == i){
        return  (double) sqrt( ((k*i) + (i*k))/(k*i)  );
    }
    else{
        return  (double) sqrt(  (( 1.0 * k*(k-1)) + ( 1.0 *  i*(i+1))) /(1.0 * i*k)  + rek(n,i+=1,k-=1) );
    }
}
double iter(int n){
    double sum = sqrt(( 1.0 * n +  1.0 *  n)/ ( 1.0 *  n));
    double k = 2;
    double l = 1;
    double f = n-1;
    double o = n;

    for(int i = 2; i <= n ; i++){
       // printf("k = %d , l = %d , f = %d , o = %d , sum = %d \n",k,l,f,o,sum);
        sum = sqrt( ((k*l) + (f*o))/(f*k) + sum );
        k+=1;
        l+=1;
        f-=1;
        o-=1;
    }
    return sum;

}


int main()
{
    int n;
    scanf("%d",&n);

    printf("Rekurzivno :  %lf \n",rek(n,1,n));
    printf("Iterativno :  %lf",iter(n));

    return 0;
}
