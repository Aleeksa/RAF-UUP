#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double rek(int n, int i, int brojilac, int raste , int opada){
   // printf("n = %d, i = %d, brojilac = %d , raste = %d , opada = %d \n",n,i,brojilac,raste,opada);
    if(n % 2 == 0){
        if(n == i){
            return sqrt((n/2.0)/2.0);
        }
        else{
            if(i % 2 == 0){
                return sqrt(1.0 * raste/brojilac+rek(n,i+1,brojilac-2,raste+1,opada));
            }
            else{
                return sqrt(1.0 * opada/brojilac+rek(n,i+1,brojilac-2,raste,opada-1));
            }
        }
    }
    else{
        if(n == i){
            return sqrt(((n+1)/2.0) / 2.0);
        }
        else{
            if(i % 2 == 0){
                return sqrt(1.0 * raste/brojilac+rek(n,i+1,brojilac-2,raste+1,opada));
            }
            else{
                return sqrt(1.0 * opada/brojilac+rek(n,i+1,brojilac-2,raste,opada-1));
            }
        }
    }
}
double iter(int n){
    double sum = 0;
    int brojilac = 2;


    if(n % 2 == 0){
        int neparni_i = n/2;
        int parni_i = (n/2)+1;
        for(int i = 1 ; i <= n; i++){
           // printf("i = %d, sum = %lf, brojilac = %d , neparni_i = %d, parni_i = %d \n",i,sum,brojilac,neparni_i,parni_i);
            if(i % 2 == 0){
                sum = sqrt(1.0*parni_i/brojilac+sum);
                parni_i+=1;
            }
            else{
                sum = sqrt(1.0*neparni_i/brojilac+sum);
                neparni_i-=1;
            }
            brojilac += 2;
        }
        return sum;
    }
    else{
        int neparni_i = (n/2)+1; 
        int parni_i = n/2;
        for(int i = 1 ; i <= n; i++){
            //printf("i = %d, sum = %lf, brojilac = %d , neparni_i = %d, parni_i = %d \n",i,sum,brojilac,neparni_i,parni_i);
            if(i % 2 == 0){
                sum = sqrt(1.0*parni_i/brojilac+sum);
                parni_i-=1;
            }
            else{
                sum = sqrt(1.0*neparni_i/brojilac+sum);
                neparni_i+=1;
            }
            brojilac += 2;
        }
        return sum;
    }
}
int main(){
    int n;
    scanf("%d",&n);

    printf("Rekurzivno   %lf \n",rek(n,1,n*2,1,n));
    printf("Iterativno   %lf",iter(n));
    return 0;
}