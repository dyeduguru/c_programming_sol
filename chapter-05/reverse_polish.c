#include<stdio.h>

#define MAX_STACK_SIZE 1024

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

int isOp(char c) {
    return c=='+' || c=='-' || c=='/' || c=='*';
}

int isDigit(char c) {
    return c>='0' && c<='9';
}

int main(int argc, char const *argv[])
{
    float stack[MAX_STACK_SIZE], result;
    int stack_top=0,c;
    while(--argc) {
        // read first charecter
        c=(*++argv)[0];
        //if its end of string continue
        if (c=='\0') {
            continue;
        }
        // check if its a operator
        if (isOp(c) && argv[0][1]=='\0') {
            if (stack_top < 2) {
                printf("two operands not found for operator %c\n", c);
                return -1;
            }
            switch(c) {
                case '+': 
                    result = stack[stack_top-2] + stack[stack_top-1];
                    break;
                case '-':
                    result = stack[stack_top-2] - stack[stack_top-1];
                    break;
                case '/':
                    result = stack[stack_top-2] / stack[stack_top-1];
                    break;
                case '*':
                    result = stack[stack_top-2] * stack[stack_top-1];
                    break;
                default:
                    printf("unknown operator: %c\n", c);
                    return -1;
            }
            stack[stack_top-2]=result;
            stack_top--;
        } 
        // check if its a number
        else if (isDigit(c) || ((c=='-' || c== '+') && isDigit(argv[0][1]))) {
            stack[stack_top++]=atoi(argv[0]);
        }
        else {
            // invalid case
            printf("unrecognized argument: %s\n", argv[0]);
            return -1;
        }
    }
    if(stack_top!=1) {
        printf("invalid number of operators\n");
        return -1;
    }
    printf("%f\n", stack[0]);
    return 0;
}
