// ACM 호텔
// https://www.acmicpc.net/problem/10250

#include <cstdio>
#pragma warning(disable: 4996)
using namespace std;

int main(void) {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int h, w, n;
		scanf("%d %d %d", &h, &w, &n);
		n -= 1;
		int x = n % h + 1, y = n / h + 1;
		printf("%d%02d\n", x, y);
	}
}

// 단순히 1호부터 채워나가면 되는데
// printf를 사용하면 더 간단하게 출력 가능