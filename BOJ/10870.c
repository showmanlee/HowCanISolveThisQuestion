// 피보나치 수 5
// https://www.acmicpc.net/problem/10870

#include <stdio.h>

int fact(int);

int main(void){
    int n;
    scanf("%d", &n);
    printf("%d", fact(n));
}

int fact(int n){
    if (n <= 1)
        return n;
    return fact(n - 1) + fact(n - 2);
}

// 대표적 재귀함수 문제
// 정확히는 재귀로도 풀 수 있는 피보나치 문제