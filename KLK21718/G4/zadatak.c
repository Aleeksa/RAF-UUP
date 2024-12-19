#include <stdio.h>
#include <stdlib.h>
double rek(int n, int i, int k, int l){
    if(n % 2 == 0){
        if(n == i){
            return (n*3)+3;
        }
        else{
            return l + k / rek(n,i+1,k-11,l+i);
        }
    }
    else{
         if(n == i){
            return (n*3)+n;
        }
        else{
            return l + k / rek(n,i+1,k-11,l+i);
        }
    }
}
double iter(int n){
    if(n % 2 == 0){
        double sum = n*3+3;
        int k = sum;
        int sab = sum - (n - 1);
        int l = 1;
        for(int i = 2; i <= n; i++){
           // printf("sab %d k %d sum %lf \n",sab,k,sum);
            sum = sab + k / sum;
            l+=1;
            sab = (sab - n) + l;
            k+=11;
        }
        return sum;
    }
    else{
        double sum = n*3+n;
        int k = n*3;
        int sab = k+1;
        int l = 1;
        for(int i = 2; i <= n; i++){
           // printf("sab %d k %d sum %lf \n",sab,k,sum);
            sum = sab + k / sum;
            l+=1;
            sab = (sab - n) + l;
            k+=11;
        }
        return sum;
    }
}
int main(){
    int n;
    scanf("%d",&n);

    if(n % 2 == 0){
        printf("Rekurzivno:   %lf\n",rek(n,1,n*10+5,n));
    }
    else{
        printf("Rekurzivno:   %lf\n",rek(n,1,n*10+n-1,n));
    }

    printf("Iterativno:   %lf",iter(n));
}
