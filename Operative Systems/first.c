#include <stdio.h>

int main()
{
    int a = 0; //It is MANDATORY to INITIAL
    int *b = &a;
    /*%c char
    %f float/double
    %s char*
    %d int
    %u unsigned int
    %p pointer*/

    printf("%p\n", b);
    printf("%p\n", &a);
    printf("%d\n", sizeof(a));
    printf("%d\n", sizeof(b));
    //it is printing what is located in that memory address (a)
}
