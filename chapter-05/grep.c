#include <stdio.h>
#include <string.h>

#define MAXLINE 4096

int myGetline(char *line, int max) {
    int c,i=0;
    while(i<max-1 && (c=getchar())!=EOF && c!='\n') {
        line[i++]=c;
    }
    if(c=='\n') {
        line[i]='\0';
        i++;
    }
    return i;
}

int main(int argc, char const *argv[])
{
    char line[MAXLINE];
    long lineNo=0;
    int c,except=0,number=0, found=0;
    while(--argc && (*++argv)[0]=='-') {
        while((c=*++argv[0])) {
            switch (c) {
                case 'x':
                    except=1;
                    break;
                case 'n':
                    number=1;
                    break;
                default:
                    printf("grep: illegal argument: %c\n", c);
                    argc=0;
                    found=-1;
                    break;
            }
        }
    }
    if (argc != 1) {
        printf("usage: grep -x -n pattern\n");
    } 
    else {
        while(myGetline(line,MAXLINE) > 0) {
            lineNo++;
            if ((strstr(line, *argv)!=NULL)!=except) {
                if (number) printf("%ld:", lineNo);
                printf("%s\n", line);
                found++;
            }
        }
    }
    return found;
}
