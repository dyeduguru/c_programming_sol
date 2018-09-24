#include <stdio.h>
#include "line_folder.h"

#define MAX_LENGTH 3

int main(int argc, char const *argv[])
{
    int c, l=0;
    int buf[MAX_LENGTH];
    int bufIdx=0;
    int bufEnd=-1;
    while ((c=getchar())!=EOF) {
        l++;
        if (c== '\n' || (l > MAX_LENGTH && c== ' ') ) {
            // flush buffer and go to new line
            flushBuffer(buf, bufEnd, bufEnd);
            putchar('\n');
            bufEnd=-1;
            bufIdx=0;
            l=0;
            if (c=='\n') {
                // if c is a new line, we already printed it. just continue to next charecter.
                continue;
            }
        }
        else if (bufIdx==MAX_LENGTH) {
            // buffer limit reached. find last space and flush till that and add new line
            int spaceIdx = getLastSpaceIdx(buf, bufEnd);
            if (spaceIdx <= 0) {
                // no non blank present. just flush buffer and keep going in the same line.
                flushBuffer(buf, bufEnd, bufEnd);
                bufEnd=-1;
                bufIdx=0;
            } else {
                // space present. flush till spaceIdx-1.
                bufEnd=flushBuffer(buf, spaceIdx-1, bufEnd);
                putchar('\n');
                bufIdx=bufEnd+1;
                l=bufIdx;
            }
        }
        buf[bufIdx]=c;
        bufEnd++;
        bufIdx=bufEnd+1;
        l++;
    }
    return 0;
}
