#include <stdio.h>
#include <limits.h>
#include <math.h>

int computeIntMax() {
   return pow(2, sizeof(int)*8-1)-1;
}

int computeIntMin() {
    return -1*pow(2, sizeof(int)*8-1);
}

struct sc {
    int a,b;
};

int main(int argc, char const *argv[])
{
    int i;
    struct sc c;
    printf("size of sc: %lu\n", sizeof(c));
    int arr[]={1,2,3};
    printf("size of arr: %lu\n", sizeof(arr)/sizeof(int));
    printf("size of int: %lu\n",sizeof(i));
    printf("int range: %d to %d\n", computeIntMin(), computeIntMax());
    printf("long range: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("char range: %d to %d\n",CHAR_MIN, CHAR_MAX);
    return 0;
}
