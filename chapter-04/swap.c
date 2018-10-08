#include <stdio.h>

#define swap(t, x, y) {t temp;temp=x;x=y;y=temp;} 

int main(int argc, char const *argv[]) {
    int x=9,y=10;
    swap(int, x,y);
    printf("%d:%d\n", x, y);
}