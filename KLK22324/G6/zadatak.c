#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double rek(int n, int i, int raste , int opada, int k){
    printf("n = %d , i = %d , raste = %d , opada = %d , k = %d \n",n,i,raste,opada,k);
    if(n == i){
        return 1.0 * raste + 1.0 * pow(k,i);
    }
    else{
         if(i % 2 == 0){
                return 1.0 * opada + 1.0 * pow(k,2) / rek(n,i+1,raste,opada-=2,k+=1);
            }
            else{
                return 1.0 * raste +1.0 * pow(k,2) / rek(n,i+1,raste+=2,opada,k+=1);
            }
    }
}
double iter(int n){
    if(n % 2 == 0){

    int nep = 'A' + 1;
    double sum = 'A' + n*n;
    int p = 'N';
    int l = n-1;
    for(int i = 2 ; i <= n ; i++){
        printf("i = %d , n = %d , sum = %lf , p = %d , nep = %d , l = %d \n",i,n,sum,p,nep,l);
        if(i % 2 == 0){
           sum =  p + pow(l,2) / sum;
        }
        else{
            sum = nep + pow(l,2) / sum;
        }
        l-=1;
        p-=1;
        nep+=1;
    }
    return sum;
    }
    else{
    int nep = 'M';
    double sum = nep + n*n;
    int p = 'B';
    int l = n-1;
    for(int i = 2 ; i <= n ; i++){
        printf("i = %d , n = %d , sum = %lf , p = %d , nep = %d , l = %d \n",i,n,sum,p,nep,l*l);
        if(i % 2 == 0){
           sum =  p + pow(l,2) / sum;
        }
        else{
            sum = nep + pow(l,2) / sum;
        }
        l-=1;
        p+=1;
        nep-=1;
    }
    return sum;
    }

}
int main(){
    int n;
    scanf("%d",&n);

    if(n % 2 == 0){
        printf("Rekurzivno:   %lf\n",rek(n,1,'H','G',1));
    }
    else{
        printf("Rekurzivno:   %lf\n",rek(n,1,'G','F',1));
    }

    printf("Iterativno:   %lf",iter(n));
    return 0;
}
