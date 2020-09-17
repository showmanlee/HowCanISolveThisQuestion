// 하노이 탑 이동 순서
// https://www.acmicpc.net/problem/11729

#include <stdio.h>
#include <math.h>

void hanoi(int n, int s, int t) {
	if (n != 1)
		hanoi(n - 1, s, 6 - s - t);
	printf("%d %d\n", s, t);
	if (n != 1)
		hanoi(n - 1, 6 - s - t, t);
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%.0lf\n", pow(2, n) - 1);
	hanoi(n, 1, 3);
}

// 재귀 함수 심화 문제로 자주 나오는 문제