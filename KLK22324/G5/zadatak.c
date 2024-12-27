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
int jelprost(int n){
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
int ispisprostih(int n){
    int brojac = 0 , i = 2;
    while(brojac < n){
        if(jelprost(i)){
            //printf("%4d",i);
            brojac+=1;
        }
        i+=1;
    }
    
    return i-1;
}
double rek(int n, int i){
    //printf("n = %d , i = %d , fib(n) = %d , prosti = %d \n",n,i,fib(i),ispisprostih(i));
    if(n == i){
        return sqrt(1.0 * fib(n)/ispisprostih(n));
    }
    else{
        return sqrt(1.0 * fib(i)/ispisprostih(i)+ rek(n,i+1));
    }
}
double iter(int n){
    int o = 0;
    double sum = 0;
    for(int i = 1; i <= n ; i++){
        printf("i = %d , n = %d , sum = %lf , fib = %d , prost = %d \n",i,n,sum,fib(n-o),ispisprostih(n-o));
        sum = sqrt(1.0 * fib(n-o)/ispisprostih(n-o)+sum);
        o+=1;
    }
    return sum;
}
int main(){
    int n;
    scanf("%d", &n);
    //printf("REK   %lf \n",rek(n+1,1));
    printf("Iter   %lf",iter(n+1));
    return 0;
}