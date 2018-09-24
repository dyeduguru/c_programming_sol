#include <stdio.h>

#define MAXLINE 1000

int mygetline(char a[], int maxline) {
    int c, i;
    for (i=0; i<maxline && (c=getchar())!=EOF && c!='\n' ; i++) {
        a[i] = c;
    }
    a[i]='\0';
    return i;
}

void copy(char from[], char to[]) {
    int i=0;
    while ((to[i]=from[i]) != '\0') {
        i++;
    }
}

int length(char s[]) {
    int i;
    for (i=0;s[i]!='\0';i++);
    return i;
}

void reverse(char s[]) {
    int i;
    int len=length(s);
    char temp;
    for (i=0;i<len/2;i++) {
        temp=s[i];
        s[i]=s[len-i-1];
        s[len-i-1]=temp;
    }
}

int main(int argc, char const *argv[])
{
    char line[MAXLINE];
    while (mygetline(line, MAXLINE) != 0) {
        reverse(line);
        printf("%s\n", line);
    }
    return 0;
}
