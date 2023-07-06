// 숫자 카드
// https://www.acmicpc.net/problem/10815

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	map<int, bool> v;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		v[p] = true;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int p;
		cin >> p;
		cout << v[p] << ' ';
	}
	cout << '\n';
}

// 현재 가지고 있는 정수 카드들과 다른 정수들이 주어졌을 때, 주어진 정수들이 적힌 카드가 있는지 판정하기

// 카드는 map으로 기록하고, 주어진 정수들을 받으며 map에 true로 찍혀있는지 출력하기