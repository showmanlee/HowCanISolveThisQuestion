// 은하철도
// https://www.acmicpc.net/problem/17250

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int group[100001];
int contain[100001];

int finding(int p) {
	if (p == group[p])
		return p;
	return group[p] = finding(group[p]);
}

int unioning(int a, int b) {
	int ga = finding(a);
	int gb = finding(b);
	if (ga < gb) {
		group[gb] = ga;
		contain[ga] += contain[gb];
		return contain[ga];
	}
	else if (ga > gb) {
		group[ga] = gb;
		contain[gb] += contain[ga];
		return contain[gb];
	}
	return contain[ga];
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		group[i] = i;
		cin >> contain[i];
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << unioning(a, b) << '\n';
	}
}

// m개의 은하철도로 이을 은하 n개의 행성 개수가 주어질 때, 은하철도(간선)으로 두 은하를 이음으로서 연결되는 행성 개수 출력하기

// union-find에서 개수까지 세야 하는 문제 - 기본적으로 union-find 분리집합 원리와 같음
// group 배열이 현재 소속된 그룹 내 가장 작은 노드 번호를 나타낸다면, contain은 이 그룹이 가지고 있는 행성 개수를 그룹 내 가장 작은 노드 번호가 대표해서 가지고 있는 것
// union 과정에서 번호가 작은 쪽으로 큰 쪽이 합쳐질 때, 작은 쪽의 행성 개수에 큰 쪽의 행성 개수를 더하고 반환한다
// 이렇게 두 은하를 잇는 과정에서 union 함수를 사용할 때, 반환값을 계속 출력해주면 됨