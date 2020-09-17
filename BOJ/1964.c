// 오각형, 오각형, 오각형...
// https://www.acmicpc.net/problem/1964

#include <stdio.h>

int main(void)
{
	int i, n;
	long result = 0;
	scanf("%d", &n);
	result += 5;
	for (i = 2; i <= n; i++)
		result += i * 3 + 1;
	printf("%d", result % 45678);
}