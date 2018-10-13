#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE 4096


char * myGetline() {
    static char s[MAX_LINE];
    int c,i=0;
    while((c=getchar())!= EOF && c!='\n') s[i++]=c;
    if(c=='\n') {
        s[i]='\0';
        i++;
    }
    if(i==0) return NULL;
    char *line = (char *)malloc(i*sizeof(char));
    int j;
    for(j=0;j<i;j++){
        line[j]=s[j];
    }
    return line;
}

int atoi(char const *s) {
    if (!s) return 0;
    int sign=1, val=0;
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
    int n=10;
    while (--argc && (*++argv)[0]=='-'){
        n=atoi(++argv[0]);
    }
    if(argc!=0) {
        printf("usage: tail -n\n");
        return -1;
    }
    if(n==0) {
        return 0;
    }
    char **s=(char **)malloc(n*sizeof(char*));
    char *line;
    int lineNum=0;
    while((line=myGetline())!=NULL) {
        s[lineNum%n]=line;
        lineNum++;
    }
    int i;
    if(lineNum<=n) {
        for(i=0;i<lineNum;i++) printf("%s\n", s[i]);
    }
    else {
        for(i=0;i<n;i++) printf("%s\n", s[(lineNum+i)%n]);
    }
    return 0;
}
