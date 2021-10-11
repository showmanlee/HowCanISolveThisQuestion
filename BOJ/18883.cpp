// N M 찍기
// https://www.acmicpc.net/problem/18883

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	int p = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << p;
			if (j != m - 1) {
				cout << ' ';
			}
			p++;
		}
		cout << '\n';
	}
}

// 1부터 n*m까지의 자연수를 n*m 보드에 하나씩 출력하기

// 하시면 되는데, 출력 속도를 빠르게 맞춰주세요 - cin.tie(NULL); ios_base::sync_with_stdio(false);
// + 한 줄의 마지막에 공백을 넣지 마세요 - 조건문이 필요합니다