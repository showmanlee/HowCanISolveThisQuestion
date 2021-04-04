// 시험 성적
// https://www.acmicpc.net/problem/9498

#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    if (n <= 100 && n >= 90)
        printf("A\n");
    else if (n <= 89 && n >= 80)
        printf("B\n");
    else if (n <= 79 && n >= 70)
        printf("C\n");
    else if (n <= 69 && n >= 60)
        printf("D\n");
    else
        printf("F\n");
}

// 흔한 조건문 문제