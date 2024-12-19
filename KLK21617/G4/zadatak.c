#include <stdio.h>
#include <stdlib.h>
double rek(int n,int i,int k){
   // printf("n = %d , i = %d , k = %d \n",n,i,k);
    if(n == i){
        return n;
    }
    else{
        if(i % 2 == 0){
            return i - k / rek(n,i+1,k-2);
        }
        else{
            return i + k / rek(n,i+1,k-2);
        }
    }
}
// double iter(int n){
//     double sum = 0;
//     int k = 4;
//     for(int i = n-1; i >= 1; i--){
//         printf("i = %d , sum = %lf , k = %d \n",i,sum,k);
//         if(i % 2 == 0){
//             /*if(sum==0){
//                 sum = i;
//                 printf("%d %d\n",sum, i);
//                 continue;
//                 }*/
            
//             sum = i - k / sum;
//         }
//         else{
//             if(sum==0) sum = i + k / (n*1.0);
//             else sum = i + k / sum;
//         }
//         printf("%lf\n", sum);
//         k+=2;
//     }
//     return sum;
// }
double iter(int n){
    double sum = n;
    int k = 4;
    for(int i = n-1; i >= 1; i--){
        printf("i = %d , sum = %lf , k = %d \n",i,sum,k);
        if(i % 2 == 0){
            sum = i - k / sum;
        }
        else{
            sum = i + k / sum; 
        }
        k+=2;
    }
    return sum;
}
int main(){
    int n;
    scanf("%d",&n);

    printf("Rekurzivno %lf \n",rek(n,1,2*n));
    printf("Iterativno %lf ",iter(n));
    return 0;
}