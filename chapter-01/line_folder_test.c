#include <stdio.h>
#include "line_folder.h"

static void test_flushBuffer_empty() {
    int buf[] = {'A', 'B', ' ', 'C', 'D'};
    int end = flushBuffer(buf,2,4);
    int i=0;
    printf("=============================TEST OUTPUT================\n");
    for (i=0;i<end;i++) {
        printf("%c ", buf[i]);
    }
}

static void test_getLastSpaceIdx() {
    int buf[] = {'A', 'B', 'C',  'D'};
    printf("%d\n", getLastSpaceIdx(buf, 5));
}

int main(int argc, char const *argv[])
{
    test_getLastSpaceIdx();
    return 0;
}

