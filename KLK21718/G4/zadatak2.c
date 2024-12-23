#include <stdio.h>
#include <stdlib.h>
#define M 100
int br(int n, int brojac){
    int temp = n;
    while(temp > 0){
        temp /= 10;
        brojac++;
    }
    return brojac;
}
void glavna(int a[][M], int n , int brf){
    for(int i = brf-1 ; i >= 0 ; i--){
        for(int j = brf-1 ; j >= 0 ; j--){
            if(i == j){
                a[i][j] = n % 10;  
                n/=10;
            }
        }
    }
}
void sporedna(int a[][M] , int n , int brf){
    for(int i = n-1 ; i >= 0 ; i--){
        for(int j = 0 ; j < brf ; j++){
            if(i + j == brf-1){
                a[i][j] = n % 10;  
                n/=10;
            }
        }
    }
}
void racun(int a[][M], int brf , int n){
    for(int i = 0 ; i < brf; i++){
        for(int j = 0 ; j < brf ; j++){
            if((i < j) &&  (i + j < brf -1)){
                if(a[i][i] == 0){
                    a[i][j] = 9;
                }
                else{
                    a[i][j] = a[i][i]-1;
                }

            }
            if((i > j) && (i + j > brf - 1)){
                if(a[i][i] == 0){
                    a[i][j] = 9;
                }
                else{
                    a[i][j] = a[i][i] - 1;
                }
            }
            if((i > j) && (i + j < brf-1)){
                if(a[i][i] == 9){
                    a[i][j] = 0;
                }
                else{
                  a[i][j] = a[i][i] + 1;
                }
            }
            if((i < j) && (i + j > brf - 1)){
                if(a[i][i] == 9){
                    a[i][j] = 0;
                }
                else{
                 a[i][j] = a[i][i] + 1;
                }
            }
        }
    }
}
void output(int a[][M], int brf){
    for(int i = 0 ; i < brf ; i++){
        for(int j = 0 ; j < brf ; j++){
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int n, a[M][M] = {0} , brojac = 0 , brf;
    scanf("%d",&n);

    brf = br(n , brojac);

    glavna(a,n,brf);
    sporedna(a,n,brf);
    racun(a, brf , n);
    output(a,brf);

    return 0;
}