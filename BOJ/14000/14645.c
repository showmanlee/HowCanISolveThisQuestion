// 와이버스 부릉부릉
// https://www.acmicpc.net/problem/14645

#include <stdio.h>
int main(void)
{
    int n, c, b, i;
    scanf("%d %d", &n, &c);
    for (i=0; i<n; i++)
        scanf("%d %d", &b, &c);
    printf("비와이\n");
}

// 당신은 버스를 운전하고 있다 -> 몇 명이 타고 내렸다 -> 버스 운전사의 나이는?
// 요런 상당히 흔하게 볼 수 있는 넌센스 문제의 비와이 버전