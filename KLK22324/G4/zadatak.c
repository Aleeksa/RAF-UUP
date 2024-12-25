#include <stdio.h>
#include <stdlib.h>
double rek(int n, int i , int s, int k, int l){
    printf("n = %d , i = %d , s = %d , k = %d , l = %d \n",n,i,s,k,l);
    if(n % 2 == 0){

    }
    else{
        if(s == i){
            return 8;
        }
        else{
            if(i % 2 == 0){
                return l - k / rek(n,i+1,s,k=k+2,l);
            }
            else{
                return n + k / rek(n,i+1,s,k=k+2,l);
            }
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);


    printf("Rek   %lf",rek(n,1,n-1,1,n+1));

}