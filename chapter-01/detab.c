#include <stdio.h>

#define TABINCR 8

int main(int argc, char const *argv[])
{
    int l,c, b;
    while((c=getchar())!=EOF) {
        if(c=='\t') {
            b=TABINCR-(l%TABINCR);
            while(b > 0) {
                putchar(' ');
                b--;
            }
        } else {
            putchar(c);
        }
        if(c=='\n') {
            l=0;
        } else {
            l++;
        }
    }
    return 0;
}
