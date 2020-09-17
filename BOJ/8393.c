// 합
// https://www.acmicpc.net/problem/8393

#include <stdio.h>
int plus(int);
int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d", plus(n));
}

int plus(int n){
    if (n == 1)
        return 1;
    return n + plus(n - 1);
}

// n까지의 합 - 반복문 말고 재귀함수로 풀어도 통과