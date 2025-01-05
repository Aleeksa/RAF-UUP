#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double rek(int n, int i, int raste, int opada, int l){
    //printf("n = %d, i = %d, raste = %d, opada = %d, l = %d \n",n,i,raste,opada,l);
    if(n == i){
        return 1.0* sqrt(raste*2);
    }
    else{
        if(i % 2 == 0){
            return sqrt(1.0* raste*l+rek(n,i+=1,raste+=1,opada,l-=2));
        }
        else{
            return sqrt(1.0* opada*l+rek(n,i+=1,raste,opada-=1,l-=2));
        }
    }
}
double iter(int n){
    if(n % 2 == 0){
    int raste = (n/2)+1;
    int opada = n/2;
    int l = 2;
    double sum = 0;
    for(int i = 1; i <= n ; i++){
            printf("n = %d , i =%d , raste = %d , opada = %d ,l = %d \n",n,i,raste,opada,l);
        if(i % 2 == 0){
            sum = sqrt(raste*l+sum);
            raste+=1;
            l+=2;
        }
        else{
            sum = sqrt(opada*l+sum);
            l+=2;
            opada-=1;
        }
    }
    return sum;
    }
    else{

    int raste = (n/2)+1;
    int opada = (n/2)+1;
    int l = 2;
    double sum = 0;
    for(int i = 1; i <= n ; i++){
            printf("n = %d , i =%d , raste = %d , opada = %d ,l = %d \n",n,i,raste,opada,l);
        if(i % 2 == 0){
            sum = sqrt(opada*l+sum);
            raste+=1;
            l+=2;
        }
        else{
            sum = sqrt(raste*l+sum);
            opada-=1;
            l+=2;
        }
    }
    return sum;
    }

}
int main(){
    int n;
    scanf("%d",&n);

    printf("Rekurzija:   %lf\n",rek(n,1,1,n,n*2));
    printf("Iterativno:   %lf",iter(n));
    return 0;
}
