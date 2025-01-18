#include <stdio.h>
#include <stdlib.h>
int main(){
int a = 100, b = 5;
int *pok1 = &b;  //pok1 = 5
int *pok2 = &a; //pok2 = 100
*pok1 = *pok1-3; //pok1 = 2
int * pok3 = pok1; //pok3 = 2
*pok3 = 8;  
b = 13; 
printf("%d %d %d %d %d",a,b,*pok1,*pok2,*pok3); //100 13 
return 0;
}