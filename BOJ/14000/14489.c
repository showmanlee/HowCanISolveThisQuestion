// 치킨 두 마리 (...)
// https://www.acmicpc.net/problem/14489

#include <stdio.h>

int main(void)
{
    int a, b, c;
    scanf("%d %d", &a, &b);
    scanf("%d", &c);
    if(a + b >= c * 2)
        printf("%d", a + b - (c * 2));
    else
        printf("%d", a + b);
}