// A+B - 3
// https://www.acmicpc.net/problem/10950

#include <stdio.h>

int main(void)
{
    int c, r[100], a, b, i;
    scanf("%d", &c);
    for (i = 0; i < c; i++)
    {
        scanf("%d", &a);
        scanf("%d", &b);
        r[i] = a+b;
    }
     for (i = 0; i < c; i++)
         printf("%d\n", r[i]);
}