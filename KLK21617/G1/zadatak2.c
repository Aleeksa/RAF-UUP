#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int brojCifara(int n)
{
    int brCifara = 0;

    while(n){
        n/=10;
        brCifara++;
    }

    return brCifara;
}
void ispisi(int a[][MAX], int n){
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n ; j++){
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }



}
int main(){
    int n , izbrojeno;
    int a[MAX][MAX];

    scanf("%d",&n);

    izbrojeno = brojCifara(n);

    for(int j = izbrojeno-1 ; j >= 0 ; j--){
        a[0][j] = n % 10;
        n/=10;
    }

    for(int i = 0 ; i < izbrojeno ; i++){
                printf("%4d",a[0][i]);

    }
   for(int i = 1; i < izbrojeno ; i++){
        for(int j = 0 ; j < izbrojeno ; j++){
            if(i % 2 == 0){
                a[i][j] = a[i-1][j]-2;
                if(a[i][j]<0){
                    a[i][j] = 10+a[i][j];
                }

            }
            else{
                a[i][j] = a[i-1][j]-1;
                if(a[i][j]<0){
                    a[i][j] = 9;
                }

            }

        }
    }

   // ispisi(a,izbrojeno);
    return 0;
}
