#include <stdio.h>
#include <stdlib.h>
int fib(int n){
    if(n == 1 || n == 2){
        return 1;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
}
double rek(int n , int i, int f , int k, int p , int t, int s){
    printf(" n = %d , i = %d , k = %d , p = %d , t = %d , s = %d \n",n,i,k,p,t,s);
    if(n % 2 == 0){
        if(n == i){
            return f;
        }
        else{
                double s = t + p;
                if(i % 2 == 0){
                    return 1.0 *  s - k / rek(n,i+1,f,k-3,t,s,s);
                }
                else{
                    return 1.0 * s + k / rek(n,i+1,f,k-3,t,s,s); 
                }
            }
        }
    else{
        if(n == i){
            return f;
        }
        else{
                int s = t + p;
                if(i % 2 == 0){
                    return 1.0 *  s - k / rek(n,i+1,f,k-3,t,s,s);
                }
                else{
                    return 1.0 * s + k / rek(n,i+1,f,k-3,t,s,s); 
                }
            }
    }
    
}
double iter(int n, int f){
    if(n % 2 == 0){
        double sum = f;
        int k = n;


        int t = 1, p = 0, s = 0;
        int j , novoj;

        for(j = 1; j < n ; j++){
        printf("i  = %d, t = %d, s = %d, p = %d \n",j,t,s,p);
        s = t + p;
        p = t;
        t = s;
        novoj = j;
        }
        printf("-------------------------------\n");
        for(int i = 2; i < n ; i++){
            printf("i = %d , p = %d , k = %d , sum = %d \n",i,p,k,sum);
            if(i % 2 == 0){
                if(novoj = n-1){
                    sum = p + k / sum;
                }
                k+=2;
                novoj--;
            }
            else{
                if(j = n-1){
                   // sum = p - k / sum;
                    k+=2;
                    j--;
                }
                
            }
        }
    }
    else{

    }
}
int main(){
    int n , f;
    scanf("%d",&n);
    f = fib(n);
    //printf("Rekurzivno   %lf",rek(n,1,f,n*3,0,1,0));
    printf("Iterativno   %lf",iter(n,f));
}