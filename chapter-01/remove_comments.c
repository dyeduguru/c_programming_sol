#include <stdio.h>

int main(int argc, char const *argv[])
{
    /*
    This is 
    a block comment
    */
    int c;
    while ((c=getchar())!=EOF) {
        if (c=='/')  {
            int prevChar=c;
            if((c=getchar())==EOF){
                return 0;
            }
            if (c=='/') {
                // line comment ignore till end of line
                while((c=getchar())!=EOF && c !='\n')
                ;
                putchar(c);
            }
            else if (c=='*') {
                // block comment ignore till end of block
                prevChar=0;
                while((c=getchar())!=EOF) {
                    if (prevChar=='*'&& c == '/') {
                        // end of block reached. break.
                        break;
                    }
                    prevChar=c;
                }
            } else {
                // not a comment. print
                putchar(prevChar);
                putchar(c);
            }    
        }
        else {
            putchar(c);
        }
    }
    return 0;
}
