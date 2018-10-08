#include <stdio.h>

int strend(char *s, char *t) {
    char *sstart=s, *tstart=t;
    while(*s++);
    s--;
    while(*t++);
    t--;
    while(*s==*t) {
        if(t==tstart) return 1;
        if(s==sstart) return 0;
        s--;t--;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", strend("abc", ""));
    return 0;
}
