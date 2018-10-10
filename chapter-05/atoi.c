#include <stdio.h>

void reverse(char *s) {
    char temp;
    char *end=s;
    while(*end!='\0')end++;
    end--;
    while(end>s) {
        temp=*s;
        *s=*end;
        *end=temp;
        s++;end--;
    }
}

int atoi(char *s) {
    if (!s) return 0;
    int sign, val=0;
    if (*s=='-') {sign=-1;s++;}
    if (*s=='+') {sign=1;s++;}
    while(*s>='0' && *s<='9') {
        val=val*10+(*s-'0');
        s++;
    }
    return sign*val;
}

int main(int argc, char const *argv[])
{
    char s[] = "abc";
    reverse(s);
    printf("%s\n", s);
    return 0;
}
