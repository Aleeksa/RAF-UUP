#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int jelprost(int n){
    for(int i = 2; i <= sqrt(n); i++){
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
            brojac+=1;
             printf("%4d",i);
        }
        i+=1;
    }
}
int main(){
    int n;
    scanf("%d", &n);

  //  printf("%d",jelprost(n));

    printf("%4d",ispisprostih(n));

    return 0;
}