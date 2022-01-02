// 로봇 조립
// https://www.acmicpc.net/problem/18116

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int group[1000001];
int cnt[1000001];

int finding(int p) {
	if (p == group[p])
		return p;
	return group[p] = finding(group[p]);
}

void unioning(int a, int b) {
	int ga = finding(a);
	int gb = finding(b);
	if (ga > gb) {
		group[ga] = gb;
		cnt[gb] += cnt[ga];
		cnt[ga] = 0;
	}
	else if (gb > ga) {
		group[gb] = ga;
		cnt[ga] += cnt[gb];
		cnt[gb] = 0;
	}

}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 1; i <= 1000000; i++) {
		group[i] = i;
		cnt[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == 'I') {
			int a, b;
			cin >> a >> b;
			unioning(a, b);
		}
		else if (c == 'Q') {
			int p;
			cin >> p;
			cout << cnt[finding(p)] << '\n';
		}
	}
}

// 서로 다른 부품들로 구성된 로봇을 구성하는 2개의 부품 쌍이 주어질 경우 묶어주고, 해당 부품을 가지고 있는 로봇이 몇 개의 부품을 가지고 있는지 출력하기

// union-find에서 그룹의 개수를 실시간으로 쿼리해줘야 하는 문제
// 부품 수가 최대 100만까지 주어질 수 있고, 또 처음에 부품이 몇 개가 있는지 주어지지 않음 - group 배열을 모두 순회하며 개수를 일일히 세기는 어려움
// 따라서 group과 함께 해당 그룹의 부품 수를 기록하는 cnt 배열을 만들어두기 - 초기값은 1
// cnt는 union 함수에서 두 그룹을 묶어줄 때 묶어지는 쪽으로 두 cnt를 합해 저장한다
// 따라서 Q로 쿼리할 때는 find로 찾은 p의 그룹 번호의 cnt를 출력하면 되는 것
// 또한 이런 방식으로 개수를 처리하면 group 개수를 셀 때 find를 돌리며 group을 갱신할 필요도 없음