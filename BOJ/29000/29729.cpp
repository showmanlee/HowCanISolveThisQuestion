// 가변 배열
// https://www.acmicpc.net/problem/29729

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int s, n, m;
	cin >> s >> n >> m;
	int u = 0;
	for (int i = 0; i < n + m; i++) {
		int p;
		cin >> p;
		if (p == 1) {
			u++;
			if (u > s) {
				s *= 2;
			}
		} else {
			u--;
		}
	}
	cout << s << '\n';
}

// 초기 크기가 모두 찼을 때 크기를 2배로 늘리는 가변 배열이 있을 때, 배열 삽입/삭제 명령들이 주어질 때 가변 배열의 최대 크기 출력하기

// 들어가고 나올 때마다 체크해주기