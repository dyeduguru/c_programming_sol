#include <stdio.h>
#include <stdlib.h> 


int len(char *s) {
    char *start=s;
    while(*s++);
    return s-start-1;
}

char* cat(char *s, char *t) {
    char *cat = malloc((len(s)+len(t))*sizeof(char));
    char *startcat=cat;
    while((*cat++ = *s++));
    cat--;
    while((*cat++ = *t++));
    return startcat;
}

int main(int argc, char const *argv[])
{
    char *a = "abc";
    char *b = "def";
    char *catted = cat("abc","def");
    printf("%s\n", catted);
    free(catted);
    return 0;
}
