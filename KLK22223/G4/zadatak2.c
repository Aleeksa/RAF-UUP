#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int najveci(int a[][100],int i, int j, int n , int m){
    int max = 0;
    if(i == 0 && j == 0){
        if((a[i][j] > max)){
            max = a[i][j];
        }
        if(a[i][j+1] > max){
            max = a[i][j+1];
        }
        if(a[i+1][j] > max){
            max = a[i+1][j];
        }
    }
    if(i == n-1 && j == m-1){
        if((a[i][j] > max)){
            max = a[i][j];
        }
        if(a[i][j-1] > max){
            max = a[i][j-1];
        }
        if(a[i-1][j] > max){
            max = a[i-1][j];
        }
    }

    if(i == n-1 && j == 0){
        if((a[i][j] > max)){
            max = a[i][j];
        }
        if(a[i][j-1] > max){
            max = a[i][j+1];
        }
        if(a[i-1][j] > max){
            max = a[i-1][j];
        }
    }

    if(i == 0 && j == m-1){
        if((a[i][j] > max)){
            max = a[i][j];
        }
        if(a[i][j-1] > max){
            max = a[i][j-1];
        }
        if(a[i+1][j] > max){
            max = a[i+1][j];
        }
    }

    //najvece uglovi

    return max;
}
int najveciivice(int a[][100],int i, int j, int n , int m){
    int max = 0;
    if(i==0){
        if(a[i][j] > max){
            max = a[i][j];
        }

        if(a[i][j-1] > max){
            max = a[i][j-1];
        }

        if(a[i][j+1] > max){
            max = a[i][j+1];
        }

        if(a[i+1][j] > max){
            max = a[i+1][j];
        }
    }
    if(j==0){
        if(a[i][j] > max){
            max = a[i][j];
        }

        if(a[i-1][j] > max){
            max = a[i-1][j];
        }

        if(a[i+1][j] > max){
            max = a[i+1][j];
        }

        if(a[i][j+1] > max){
            max = a[i][j+1];
        }
    }

    if(j==m-1){
        if(a[i][j] > max){
            max = a[i][j];
        }

        if(a[i-1][j] > max){
            max = a[i-1][j];
        }

        if(a[i+1][j] > max){
            max = a[i+1][j];
        }

        if(a[i][j-1] > max){
            max = a[i][j-1];
        }
    }

    if(i==n-1){
        if(a[i][j] > max){
            max = a[i][j];
        }

        if(a[i-1][j] > max){
            max = a[i-1][j];
        }

        if(a[i][j-1] > max){
            max = a[i][j-1];
        }

        if(a[i][j+1] > max){
            max = a[i][j+1];
        }
    }

    return max;
}
void unos(int m , int n, int a[][100]){
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m ; j++){
            scanf("%d",&a[i][j]);
        }
    }
}
void racun(int m , int n , int a[][100], int b[][100]){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
                if((i == 0 || i == n-1) && (j == 0 || j == m-1)){
                    b[i][j] = najveci(a,i,j,n,m);
                }
                else if( i==0 || i==n-1 || j == 0 || j == m-1){
                    b[i][j] = najveciivice(a,i,j,n,m);
                }
                else{
                    b[i][j] = (a[i][j-1] - a[i][j+1]) - (a[i-1][j] + a[i+1][j]);
            }
        }
    }
}
void ispis(int m, int n, int a[][100],int b[][100]){
    /*for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m ; j++){
            printf("%4d",a[i][j]);
        }
    printf("\n");
    }*/

    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m ; j++){
            printf("%4d",b[i][j]);
        }
    printf("\n");
    }
}
int main(){
    int n , m , a[100][100] = {0}, b[100][100] = {0};
    scanf("%d %d",&n , &m);

    unos(m,n,a);
    racun(m,n,a,b);
    ispis(m,n,a,b);

    return 0;
}
