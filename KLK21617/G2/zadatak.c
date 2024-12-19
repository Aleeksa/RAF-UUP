#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double rek(int n, int i, int k){
    if(k == 1){
        return 1;
    }
    else{
        if(i % 2 == 0){
            return k + sqrt(2.0) / rek(n,i+1,k-1);
        }
        else{
            return k + sqrt(1.0) / rek(n,i+1,k-1);
        }
    }
}
double iter(int n){
    double sum = 0;
    for(int i = 0; i <= n; i++){
        if(i % 2 == 0){
            sum = 1.0 * i + sqrt(1) / sum;
        }
        else{
            sum = 1.0 * i + sqrt(2) / sum; 
        }
    }    
    return sum;
}
int main(){
    int n;
    scanf("%d",&n);

    printf("Rekurzivno %lf \n",rek(n,1,n));
    printf("Iterativno %lf",iter(n));

}