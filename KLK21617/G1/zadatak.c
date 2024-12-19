#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double rek(int n,int i,int k){
    printf("n = %d, i = %d, k = %d \n",n,i,k);
    if(k == 1){
        return sqrt(2.0);
    }
    else{
        if(i % 2 == 0){
            return sqrt(2.0 / k + rek(n,i+1,k-1));
        }
        else{
            return sqrt(1.0 / k + rek(n,i+1,k-1));
        }
    }
}
double iter(int n){
    double sum = 0;

    for(int i = 1; i <= n; i++){
        if(i % 2 == 0){
            sum = sqrt(1.0/i+sum);
        }
        else{
            sum = sqrt(2.0/i+sum);
        }
    }
    return sum;
}
int main(){
    int n;
    scanf("%d",&n);
    
    printf("Rekurzivno : %lf\n",rek(n,1,n));
    printf("Iterativno : %lf",iter(n));

    return 0;
}