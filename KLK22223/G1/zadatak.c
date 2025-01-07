#include <stdio.h>
#include <stdlib.h>
int fakt(int n){
    if(n == 0){
        return 1;
    }
    else{
        return n*fakt(n-1);
    }
}

double rek(int n, int i, int parno, int neparno, int k, int l){
    //printf("n = %d, i = %d , parno = %d , neparno = %d , k = %d , l = %d \n",n,i,parno,neparno,k,l);
    if(n == i){
        return 1.0 *fakt(parno) + l;
    }
    else{
        if(i % 2 == 0){
            return 1.0 * fakt(parno)+l/rek(n,i+=1,parno+=2,neparno,k,l-=4);
        }
        else{
            return 1.0 * neparno+fakt(k)/rek(n,i+=1,parno,neparno-=4,k+=2,l);
        }
    }
}
double iter(int n){
    if(n % 2 == 0){
    int neparno = n-2;
    int parno = 4;
    int k = n/3;
    int l = n-1;
    double sum = fakt(n) + neparno;

    for(int i = 2; i <= n ; i++){
            //printf("i = %d , n = %d , neparno = %d , parno = %d , k = %d , l = %d \n",i,n,neparno,parno,k,l);
        if(i % 2 == 0){
            sum = parno + fakt(l) / sum;
            parno+=4;
            l-=2;
            k+=4;
        }
        else{
            sum = fakt(neparno) + k/sum;
            neparno-=2;
        }
    }
    return sum;
    }
    else{
    int neparno = 6;
    int parno = n-1;
    int k = n-2;
    int l = 4;
    double sum = fakt(n) + 2;

    for(int i = 2; i <= n ; i++){
           // printf("i = %d , n = %d , neparno = %d , parno = %d , k = %d , l = %d \n",i,n,neparno,parno,k,l);
        if(i % 2 == 0){
            sum = fakt(parno) + l / sum;
            parno-=2;
            l+=4;
        }
        else{
            sum = neparno + fakt(k) /sum;
            neparno+=4;
            k-=2;
        }
    }
    return sum;
    }
}
int main(){
    int n;
    scanf("%d",&n);

    printf("Rekurzivno:   %lf\n",rek(n,1,2,n*2,1,(n*2)-2));
    printf("Iterativno:   %lf",iter(n));
    return 0;
}
