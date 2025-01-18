#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void zad3(int niz[], int duzina, int *elem){
    int a = niz[1] + 2; // a = -1 + 2 = 1
    int *p = niz+1; // adr2
    niz[0] = *(p+1); 
    *p = a;
    *elem = 6;
}
int main(){
    int ary[4] = {1, -1, 1, 2};
    zad3(ary, 2 ,ary+1);

    printf("%d %d %d %d\n", ary[0], ary[1], ary[2], ary[3]);
    return 0;
}