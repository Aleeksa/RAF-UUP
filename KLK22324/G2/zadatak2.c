#include <stdio.h>
#include <stdlib.h>
int o = 0;
double rek(int n , int i, int raste , int opada , int k){
    if(n % 2 == 0){
    printf("n = %d , i = %d , raste = %d , opada = %d , k = %d \n",n,i,raste,opada,k);
    if(n == i){
        return 1.0 * opada - 1.0;
    }
    else{
        if(i % 2 == 0){
            return 1.0 * opada - k / rek(n,i+=1,raste,opada-=1,k+=1);
        }
        else{
            return 1.0 * raste + k / rek(n,i+=1,raste+=1,opada,k+=1);
        }
    }
        }
    else{
        printf("n = %d , i = %d , raste = %d , opada = %d , k = %d \n",n,i,raste,opada,k);
    if(n == i){
        return 1.0 * opada + 1.0;
    }
    else{
        if(i % 2 == 0){
            return 1.0 * opada - k / rek(n,i+=1,raste,opada-=1,k+=1);
        }
        else{
            return 1.0 * raste + k / rek(n,i+=1,raste+=1,opada,k+=1);
        }
    }
    }

}
double iter(int n){

    if(n % 2 == 0){
    double sum = (n/2) - 1;
    double raste = n/2;
    double opada = n+2;
    double k = 1;

    for(int i = 2; i <= n ; i++){
            printf("i = %d , n = %d , sum = %d , raste = %d , opada = %d , k = %d \n",i,n,sum,raste,opada,k);
        if(i % 2 == 0){
            sum = opada + k / sum;
            raste+=1;
            opada-=1;
        }
        else{
            sum = raste - k / sum;

        }
    }
    return sum;
    }
    else{

    double sum = (n/2) - 1;
    double raste = (n/2)+1;
    double opada = n+3;
    double k = 1;

    for(int i = 2; i <= n ; i++){
        printf("i = %d , n = %d , sum = %d , raste = %d , opada = %d , k = %d \n",i,n,sum,raste,opada,k);
        if(i % 2 == 0){
            sum = opada - k / sum;
            raste+=1;
            opada-=1;
        }
        else{
            sum = raste + k / sum;
        }
    }
    return sum;
    }

}
int main(){
    int n;
    scanf("%d",&n);

    printf("Rekurizvno : %lf \n",rek(n,1,n,n-1,1));
    printf("Iterativno :  %lf ",iter(n));
    return 0;
}
