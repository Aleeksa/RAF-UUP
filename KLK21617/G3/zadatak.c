#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double rek(int n, int k, int j){
    //printf("n = %d , k = %d , j = %d \n",n,k,j);
    if(n == k){
        return sqrt(n);
    }
    else{
        if(j <= 0){
            j = 3;
        }
        return sqrt(k * j + rek(n,k+1,j-1));
    }
}
double iter(int n){
    double sum = 0;
    int j = 1;
    for(int i = n; i >= 1 ; i--){
        printf("i = %d , sum = %lf, j = %d\n",i,sum,j);
        sum = sqrt(i * j + sum);
        j++;
        if(j > 3){
            j = 1;
        }
    }
    return sum;
}
int main(){
    int n;
    scanf("%d",&n);

    printf("Rekurzivno %lf\n",rek(n,1,n/2));
    printf("Iterativno %lf",iter(n));
    return 0;
}