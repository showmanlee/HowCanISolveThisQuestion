// 아!
// https://www.acmicpc.net/problem/4999

#include <stdio.h>
#include <string.h>

int main(void) {
	char a[1001], b[1001];
	scanf("%s", a);
	scanf("%s", b);
	for (int i = 0; i < 1001; i++) {
		if (a[i] == 'h') {
			if (b[i] == 'h')
				printf("go");
			else
				printf("no");
			break;
		}
		else if (b[i] == 'h') {
			printf("go");
			break;
		}
	}
}

// 문자열 길이 함수 - C++ 등 문자열 지원 언어로 풀면 더 간단했을 텐데