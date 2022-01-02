// 팩토리얼
// https://www.acmicpc.net/problem/10872

#include <stdio.h>

int fact(int);
int main(void){
    int n;
    scanf("%d", &n);
    printf("%d", fact(n));
}

int fact(int n){
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

// 최대값(여긴 12) 잘못 주면 시스템 뻗기 참 좋은 문제