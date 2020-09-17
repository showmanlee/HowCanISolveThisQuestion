// 이진수 합
// https://www.acmicpc.net/problem/8741

#include <stdio.h>

int main(void)
{
	int i, n, result = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		printf("1");
	for (i = 1; i < n; i++)
		printf("0");
}

// k = 1 -> 1 = 1(2)
// k = 2 -> 3 + 2 + 1 = 6 = 110(2)
// k = 3 -> 7 + 6 + 5 + 4 + 3 + 2 + 1 = 28 = 11100(2)
// k = 4 -> 1~15까지의 합 = 120 = 1111000(2)
// 규칙성이 있음