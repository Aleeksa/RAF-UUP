#include <stdio.h>
#include <stdlib.h>
int main(){
     int a[100][100] = {
        {3, 1, 2},
        {9, 5, 7},
        {4, 8, 6}
    };
    int n = 3;
    int b[100][100] = {0};
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < n ; j++){
            for(int k = 0 ; k < n ; k++){
                for(int l = 0 ; l < n ; l++){
                    if(a[i][j] < a[k][l]){
                    int temp = a[i][j];
                    a[i][j] = a[k][l];
                    a[k][l] = temp;
                }
                }
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}