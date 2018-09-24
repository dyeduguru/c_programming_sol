#include<stdio.h>

int flushBuffer(int buf[], int till, int end) {
    int i;
    for(i=0;i<=till;i++) {
        putchar(buf[i]);
    }
    int start=till+1;
    for(i=0;i+start<=end;i++) {
        buf[i]=buf[i+start];
    }
    return i-1;
}

int getLastSpaceIdx(int buf[], int end)  {
    int i;
    for (i=end;i>=0;i--) {
        if (buf[i]==' ') {
            break;
        }
    }
    return i;
}