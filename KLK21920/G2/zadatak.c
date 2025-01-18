#include <stdio.h>
#include <stdlib.h>
int fakt(int n){
    if(n <= 0){
        return 1;
    }
    else{
        return n*fakt(n-1);
    }
}
double rek(int i, double n, int parno , int neparno , int k , int l){
    if(n == i){
        return (double)parno + fakt(l);
    }
    else{
        if(i % 2 == 0){
            return (double)parno + fakt(l) / rek(i+=1,n,parno-=1,neparno,k,l+=1);
        }
        else{
            return (double)neparno + fakt(k) / rek(i+=1,n,parno,neparno+=1,k-=1,l);
        }
    }
}
double iter(int n){
    if(n % 2 == 0){
    double sum = 4+fakt(n/2);
    int parno = 5;
    int neparno = 3;
    int l = 4;
    int k = 2;

    for(int i = n-1 ; i >= 1; i--){
        //printf("i = %d , parno = %d , neparno = %d, l = %d , k = %d , sum = %d \n",i,parno,neparno,l,k,sum);
        if(i % 2 == 0){
           sum = 1.0 *  parno + fakt(k) / sum;
           parno+=1;
           k-=1;
        }
        else{
            sum = 1.0 *  neparno + fakt(l) / sum;
            neparno-=1;
            l+=1;
        }
    }
    return sum;
    }
    else{
    double sum = 4+fakt(4);
    int parno = 3;
    int neparno = 5;
    int l = 3;
    int k = 5;

    for(int i = n-1 ; i >= 1; i--){
      //  printf("i = %d , parno = %d , neparno = %d, l = %d , k = %d , sum = %d \n",i,parno,neparno,l,k,sum);
        if(i % 2 == 0){
        sum = 1.0 * neparno + fakt(l) / sum;
        neparno+=1;
        l-=1;
        }
        else{
        sum = 1.0 *  parno + fakt(k) / sum;
        parno-=1;
        k+=1;
        }
    }
    return sum;
    }

}
int main(){
    int n;
    scanf("%d",&n);

    printf("Rekurzivno:  %lf\n", rek(1,n,n,1,n,1));
    printf("Iterativno:  %lf", iter(n));
    return 0;
}
