#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int brojac = 0;
int c = 0;
void racun(int n, int a[][100]){

    while(brojac < n/2){
    int povecaj = 1;
    int temp = 0;
    int l = 2;

    if(brojac != 0)

    for(int i = brojac; i < n-brojac ; i++){
        for(int j = brojac ; j < n-brojac ; j++){
            if(i == brojac || j == n-brojac-1){
                int b = pow(povecaj,brojac+1);
                a[i][j] = b++;// % 10;
                povecaj+=1;

                if(a[i][j] >= 10){
                    //a[i][j] %= 10;
                }

                temp = povecaj;

            }
        }
        for(int j = n-brojac-2 ; j >= brojac; j--){
            if(i == n-brojac-1){
                int b = pow(temp-2,brojac+1);
                a[i][j] = b++ ;//% 10;
                temp-=1;
                }
            }

        temp-=2;
        for(int i = n-brojac-2 ; i >= brojac+1 ; i--){
            int b = pow(temp,brojac+1);
            a[i][brojac] = b++ ;//% 10;
            temp-=1;
        }
        }
        else
        for(int i = brojac; i < n-brojac ; i++){
        for(int j = brojac ; j < n-brojac ; j++){
            if(i == brojac || j == n-brojac-1){
                a[i][j] = povecaj ;
                povecaj+=1;
                if(a[i][j] >= 10){
                    ////a[i][j] %= 10;
                }

                temp = povecaj;

            }
        }
        for(int j = n-brojac-2 ; j >= brojac; j--){
            if(i == n-brojac-1){
                a[i][j] = (temp-2) ;//% 10;
                temp-=1;
                }
            }

        temp-=2;
        for(int i = n-brojac-2 ; i >= brojac+1 ; i--){
            a[i][brojac] = temp ;//% 10;
            temp-=1;
        }
        }
        brojac++;

    }
}


void ispis(int n, int a[][100]){
  for(int i = 0; i < n ; i++){
    for(int j = 0; j < n ; j++){
        printf("%4d",a[i][j]);
    }
    printf("\n");
  }
}
int main(){
    int n , a[100][100] = {0};
    scanf("%d",&n);

    racun(n,a);
    ispis(n,a);


    return 0;
}
