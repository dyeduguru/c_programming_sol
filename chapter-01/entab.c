#include <stdio.h>

#define TABINCR 8

void fillWithChars(char c, int count) {
    int i;
    for (i=0;i<count;i++) {
        putchar(c);
    }
}

int main(int argc, char const *argv[])
{
    int l=0,c,spaces;
    c=getchar();
    while (c != EOF) {
        if (c==' ') {
            // if space, keep reading till you get spaces and replace them with tabs and spaces
            int spaces=1;
            while((c=getchar()) == ' ') {
                spaces++;
            }
            int blanksWithTab=TABINCR-(l%TABINCR);
            int tabs=0;
            while (blanksWithTab <= spaces) {
                spaces-=blanksWithTab;
                l+=blanksWithTab;
                blanksWithTab=TABINCR;
                tabs++;
            }
            l+=spaces;
            fillWithChars('\t', tabs);
            fillWithChars(' ', spaces);
        } else {
            // if not space, put the charecter back and read the next one
            putchar(c);
            l++;
            c=getchar();
        }
        if (c=='\n') {
            l=-1;
        }
    }
    return 0;
}
