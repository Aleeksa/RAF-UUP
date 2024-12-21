#include <stdio.h>
void input(int n, int a[][100]){
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n ; j++){
            //printf("a[%d][%d]=",i,j);
            scanf("%d",&a[i][j]);
        }
    }
}
void racun(int n, int a[][100], int b[][100]){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(j==0){//levo
                b[i][j] = a[i][1];
            }
            else if(j == n-1){//desno
                b[i][j] = a[i][n-2];
                }
            else{
                b[i][j] = a[i][j-1] + a[i][j+1];
            }
            }
        }
    }
void output1(int n , int a[][100]){
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n ; j++){
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
}
int main(){

    int n, a[100][100] = {0};
    scanf("%d",&n);

    int b[100][100] = {0};


    input(n,a);
    printf("-----------------\n");
    output1(n,a);
    racun(n,a, b);
    printf("-----------------------\n");
    output1(n,b);

    return 0;
}