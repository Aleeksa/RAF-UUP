#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int jelprost(int n){
    for(int i = 2; i <= sqrt(n) ; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}
int ispisprostih(int n){
    int brojac = 0 , i = 2;
    while(brojac <= n){
        if(jelprost(i)){
            //printf("%4d",i);
            brojac+=1;
        }
        i+=1;
    }
    return i-1;
}
void levo(int a[][100], int n){
    int k = n;
    for(int i = n-1; i >= 0; i--){
        a[i][0] = ispisprostih(n-k);
        k-=1;
         if(a[i][0] >= 10){
            a[i][0] %= 10;
        }
    }
}
void gore(int a[][100], int n){
    int k = 0;
        for(int j = 1; j < n ; j++){
            a[0][j] = ispisprostih(n+k) ;//% 10;
            k+=1;
        }
}
void desno(int a[][100], int n){
        int k = n - 1;
        for(int i = 1; i < n ; i++){
            a[i][n-1] = ispisprostih(n+k);//% 10;
            k+=1;
        }
}
void levo2(int a[][100], int n){
    int k = n+n-2;
    if(n % 2 == 0){
        for(int i = n-1 ; i >= 1 ; i--){
       a[i][1] = ispisprostih(n+k+1);
        k+=1;
        }
    }
    else{
    for(int i = n-1 ; i >= 1 ; i--){
       a[i][1] = ispisprostih(n+k);
        k+=1;
        }
    }
}
void desno2(int a[][100] , int n){
    int k = 2*n;
    for(int j = 2 ; j <= n-2 ; j++){
        a[1][j] = ispisprostih(n+k+2);
        k+=1;
    }
}
void dole2(int a[][100], int n){
    int k = 2*n+2;
    for(int i = 2 ; i <= n-1 ; i++){
        a[i][n-2] = ispisprostih(n+k+2);
        k+=1;
    }
}
void gore3(int a[][100], int n){
    int k = 2*n+n-1;
    for(int i = n ; i >= n-3 ; i--){
        a[i][n-3] = ispisprostih(n+k+2);
        k+=1;
    }
}
void ispis(int a[][100], int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < n ; j++){
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int n , a[100][100] = {0};
    scanf("%d",&n);

    levo(a,n);
    gore(a,n);
    desno(a,n);
    levo2(a,n);
    desno2(a,n);
    dole2(a,n);
    gore3(a,n);
    ispis(a,n);

   // printf("%d \n",ispisprostih(n));
    return 0;
}
