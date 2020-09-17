// 나머지
// https://www.acmicpc.net/problem/10430

#include <stdio.h>
int main(void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", (a+b)%c);
    printf("%d\n", (a%c+b%c)%c);
    printf("%d\n", (a*b)%c);
    printf("%d\n", (a%c*b%c)%c);  
}

// 시키는 대로 했습니다