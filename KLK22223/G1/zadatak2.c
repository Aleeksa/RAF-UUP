#include <stdio.h>
#include <stdlib.h>
void unos(int a[][100], int n){
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j++){
            scanf("%d",&a[i][j]);
        }
    }
}

void racun(int a[][100], int b[][100] , int n){
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j++){
            if(i == 0 || j == 0 || i == n-1 || j == n-1){
                b[i][j] = a[i][j];
                for(int k = 0 ; k < n ; k++){
                    for(int l = 0 ; l < n ; l++){
                             if(k == n-1){
                        if(a[i][j] > a[k][l]){
                        int temp = a[i][j];
                        a[i][j] = a[k][l];
                        a[k][l] = temp;
                            }
                        }
                        if(l == 0){
                        if(a[i][j] > a[k][l]){
                        int temp = a[i][j];
                        a[i][j] = a[k][l];
                        a[k][l] = temp;
                            }
                        }
                        if(k == 0){
                        if(a[i][j] < a[k][l]){
                        int temp = a[i][j];
                        a[i][j] = a[k][l];
                        a[k][l] = temp;
                            }
                        }
                        if(l == n-1){
                        if(a[i][j] < a[k][l]){
                        int temp = a[i][j];
                        a[i][j] = a[k][l];
                        a[k][l] = temp;
                            }
                        }
                    }
                }
            }
            else if(i == 1 || j == 1|| i == n-2 || j == n-2){
            b[i][j] = a[i][j];
            for(int k = 1 ; k < n-1 ;k++){
            for(int l = 1 ; l < n-1 ; l++){
                    if(k == n-2){
                        if(a[i][j] < a[k][l]){
                        int temp = a[i][j];
                        a[i][j] = a[k][l];
                        a[k][l] = temp;
                            }
                        }
                        if(l == 1){
                        if(a[i][j] < a[k][l]){
                        int temp = a[i][j];
                        a[i][j] = a[k][l];
                        a[k][l] = temp;
                            }
                        }
                        if(k == 1){
                        if(a[i][j] > a[k][l]){
                        int temp = a[i][j];
                        a[i][j] = a[k][l];
                        a[k][l] = temp;
                            }
                        }
                        if(l == n-2){
                        if(a[i][j] > a[k][l]){
                        int temp = a[i][j];
                        a[i][j] = a[k][l];
                        a[k][l] = temp;
                            }
                        }

               }
            }}else{
                b[i][j] = a[n/2][n/2];
            }
        }
    }
}

void ispis(int b[][100], int n){
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j++){
            printf("%4d",b[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int n, a[100][100] = {0};
    int b[100][100] = {0};

    scanf("%d",&n);

    unos(a,n);
    racun(a,b,n);
    ispis(a,n);

    return 0;
}
