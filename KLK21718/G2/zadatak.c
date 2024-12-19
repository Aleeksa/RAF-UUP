#include <stdio.h>
#include <stdlib.h>
double rek(int n, int i, int brojilac, int parno,int neparno){
    //printf("i = %d , n = %d , brojilac = %d , parno = %d , neparno = %d  \n",i,n,brojilac,parno,neparno);
    if(n % 2 == 0){
        if(n == i){
            return n/2;
        }
        else{
            if(i % 2 == 0){
                return 1.0 * parno + brojilac / rek(n,i+1,brojilac-2,parno+1,neparno);
            }
            else{
                return 1.0 * neparno + brojilac / rek(n,i+1,brojilac-2,parno,neparno-1);
            }
        }
    }
    else{
        if(n == i){
            return (n/2)+1;
        }
        else{
            if(i % 2 == 0){
                return 1.0 * parno + brojilac / rek(n,i+1,brojilac-2,parno+1,neparno);
            }
            else{
                return 1.0 * neparno + brojilac / rek(n,i+1,brojilac-2,parno,neparno-1);
            }
        }
    }
}
double iter(int n){
    if(n % 2 == 0){
        double sum = n/2;
        int brojilac = 4;
        int parno = (n/2)+1;
        int neparno = (n/2)-1;
        for(int i = 2 ; i <= n ; i++){
          //  printf("sum = %lf , brojilac = %d , parno = %d , neparno = %d , i = %d\n",sum,brojilac,parno,neparno,i);
            if(i % 2 == 0){
                sum = parno + brojilac / sum;
                parno+=1;
            }
            else{
                sum = neparno + brojilac / sum;
                neparno-=1; 
            }
            brojilac+=2;
        }
        return sum;
    }
    else{
        double sum = (n/2)+1;
        int brojilac = 4;
        int parno = n/2;
        int neparno = sum+1;
        for(int i = 2 ; i <= n ; i++){
          //  printf("sum = %lf , brojilac = %d , parno = %d , neparno = %d , i = %d\n",sum,brojilac,parno,neparno,i);
            if(i % 2 == 0){
                sum = parno + brojilac / sum;
                parno-=1;
            }
            else{
                sum = neparno + brojilac / sum;
                neparno+=1; 
            }
            brojilac+=2;
        }
        return sum;
    }
}
int main(){
    int n;
    scanf("%d",&n);

    printf("Rekurzivno:   %lf \n",rek(n,1,n*2,1,n));
    printf("Iterativno:   %lf",iter(n));
}