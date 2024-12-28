#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int fib(int n){
    if(n == 1 || n == 2){
        return 1;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
}
void gore(int a[][100], int n){
    for(int j = n-1 ; j >= 0 ; j--){
        a[0][j] = fib(j+1) % 10;
    }
}
void sporedna(int a[][100], int n){
    for(int i = 1; i < n ; i++){
        for(int j = n-1 ; j >= 0 ; j--){
            if(i + j == n - 1){
                a[i][j] = fib(n+i) % 10;
            }
        }
    }
}
void dole(int a[][100], int n){
    int o = 0;
    for(int j = 1 ; j < n ; j++){
        a[n-1][j] = fib(2*n+o)% 10;
        o+=1;
    }
}
void racun(int a[][100], int n){
    for(int i = 1; i <= n - 2 ; i++){
        for(int j = 0 ; j <= n - 1 ; j++){
           if(i + j > n - 1){
            a[i][j] = (int)pow(j,i) % 10;
           }
        }
        for(int j = n - 1 ; j >= 0 ; j--){
            if(i+j < n - 1){
                a[i][j] = abs(a[i][j+1] - a[i][j+2]) % 10;
            }
        }
    }
}

void ispis(int a[][100],int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < n ; j++){
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n, a[100][100] = {0};
    scanf("%d",&n);

    gore(a,n);
    sporedna(a,n);
    racun(a, n);
    dole(a, n);

    ispis(a,n);
    return 0;
}
