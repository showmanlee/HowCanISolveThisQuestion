// 벌집
// https://www.acmicpc.net/problem/2292

#include <stdio.h>
int main(void)
{
    int n,i;
    scanf("%d", &n);
    if (--n == 0)
        i=1;
    else
        for (i=1;n>0;i++)
            n -= i*6;
    printf("%d\n", i);
}