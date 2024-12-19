#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double rek(int n , int i, int k, int im){
   // printf("i = %d , n = %d , k = %d , im = %d \n",i,n,k,im);
    if(n % 2 == 0){
        if(n == i){
            return sqrt(10.0/im);
        }
        else{
            return sqrt(1.0* k/im+rek(n,i+1,k-11,im+i));
        }
    }
    else{
        if(n == i){
            return sqrt(10.0/im);
        }
        else{
            return sqrt(1.0* k/im+rek(n,i+1,k-11,im+i));
        }
    }
}
double iter(int n){
    if(n % 2 == 0){
        double sum = 0;
        int im = ((n*3)+3);
        int br = 10.0;
        int z = n;
        for (int i = 1; i <= n; i++)
        {
           // printf("sum = %lf , im = %d, br = %d, z = %d \n",sum,im,br,z);
            sum = sqrt(1.0 * br/im+sum);
            br+=11;
            z-=1;
            im=im-z;
        }
        return sum;
        
    }
    else{
        double sum = 0;
        int im = ((n*3)+n);
        int br = 10.0;
        int z = n;
        for (int i = 1; i <= n; i++)
        {
           // printf("sum = %lf , im = %d, br = %d, z = %d \n",sum,im,br,z);
            sum = sqrt(1.0 * br/im+sum);
            br+=11;
            z-=1;
            im=im-z;
        }
        return sum;
    }
}
int main(){
    int n;
    scanf("%d",&n);

    if(n % 2 == 0){
        printf("Rekurzivno   %lf \n",rek(n,1,n*10+5,n));
    }
    else{
        printf("Rekurzivno   %lf \n",rek(n,1,(n*10)+(n-1),n));
    }

    printf("Iterativno:   %lf \n",iter(n));
}