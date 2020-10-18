// 수 정렬하기 3
// https://www.acmicpc.net/problem/10989

#include <iostream>
using namespace std;
int c[10001];

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		c[p]++;
	}
	for (int i = 1; i < 10001; i++)
		for (int j = 0; j < c[i]; j++)
			cout << i << '\n';
}

// 천만 개의 숫자, 그러나 숫자 범위는 1~10000
// 병합 정렬을 구현하느니 차라리 카운팅 정렬을 쓰는 게 더 나은 문제