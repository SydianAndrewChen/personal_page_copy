#include <stdio.h>

typedef unsigned char * byte_pointer;

void show_byte(byte_pointer start, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++)
        printf("%.2x", start[i]);
    printf("\n");
}

void show_int(int n)
{
    show_byte((byte_pointer)(&n), sizeof(n));
}

int main()
{
    show_int(0x01234567);
}