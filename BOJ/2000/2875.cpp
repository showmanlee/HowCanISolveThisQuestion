// 대회 or 인턴
// https://www.acmicpc.net/problem/2875

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		if (n / 2 >= m) {
			n--;
		} else {
			m--;
		}
	}
	cout << min(n / 2, m) << '\n';
}

// 여자 2명, 남자 1명이 한 팀으로 구성되는 대회에 여학생 n명과 남학생 m명이 지원하고, 그 중 k명을 인턴십에 차출해야 할 때, 만들 수 있는 팀의 최대 개수 출력하기

// 기본적으로 만들 수 있는 팀의 수는 min(n / 2, m)
// 여기서 인턴십 차출 인원은 n / 2, m 중 더 큰 쪽에서 빼준다