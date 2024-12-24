#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int fib(int n){
    if(n == 1 || n == 2){
        return 1;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
}
int prost(int n){
    if(n <= 1){
        return 0;
    }
   for(int i = 2 ; i <= sqrt(n) ; i++){
        if(n % i == 0){
            return 0;
        }
   }
   return 1;
}
double rek(int n, int i, int p , int t , int s , int prost){
    printf("n = %d , i = %d , p = %d , t = %d , s = %d \n",n,i,p,t,s);
    if(n == i){
        return sqrt(fib(n)/1);
    }
    else{
        s = t + p;
        return sqrt(t/ + rek(n,i+1,t,s,s,prost));
    }
}
double iter(int n, int f){
    double sum = 0;
    int o = 0;
    for(int i = 1 ; i <= n ; i++){
        printf("n = %d , i = %d , fib(n) = %d , sum = %d \n",n,i,fib(n-o),sum);
        sum = sqrt(1.0 * fib(n-o)+sum);
        o++;
    }
    return sum;
}
int main(){
    int n , novoN , f , p;
    scanf("%d",&n);

    novoN = n + 1;

    f = fib(novoN);
    p = prost(n);
    
    printf("Rekurzivno   %lf \n",rek(novoN,1,1,1,0,p));
    printf("Iterativno   %lf",iter(novoN, f));
    return 0;
}