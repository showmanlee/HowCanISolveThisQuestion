// 집합의 표현
// https://www.acmicpc.net/problem/1717

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[1000001];
int n;

int finding(int p) {
	if (p == parent[p])
		return p;
	parent[p] = finding(parent[p]);
	return parent[p];
}

void unioning(int a, int b) {
	int pa = finding(a);
	int pb = finding(b);
	if (pa > pb)
		parent[pa] = pb;
	else if (pb > pa)
		parent[pb] = pa;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	for (int i = 0; i < m; i++) {
		int x, a, b;
		cin >> x >> a >> b;
		if (x == 0)
			unioning(a, b);
		else
			cout << (finding(a) == finding(b) ? "YES" : "NO") << '\n';
	}
}

// 초기 상태에서 개별적으로 집합을 형성하고 있는 1~n에 대해 합집합 연산과 두 원소가 같은 집합에 포함되어 있는지 확인하기

// union 함수와 find 함수를 활용해 두 집합을 하나로 합치고 같은 집합인지 확인하는 union-find 알고리즘을 배워보자
// 이를 활용하기 위해 사용하는 parent 알고리즘은 자신과 '연결'된 나보다 작은 원소를 기록한다 - 초기에는 parent[a] = a
// 연결되었다는 것은 곧 해당 원소가 대표하는 집합에 포함되었다는 것을 의미
// find 함수는 현재 자신이 속한 집합 중 가장 작은 원소 - 즉 집합을 대표하는 원소가 무엇인지를 확인하는 함수
// 그러면서 parent 배열의 값들을 해당 집합의 대표 원소로 갱신시켜주는 함수 - parent[a] == a면 a 반환, 그렇지 않으면 parent[a]를 find(parent[a])(재귀)로 갱신한 후 반환
// union 함수는 서로 다른 집합의 두 원소를 합치는 함수
// a와 b의 집합 대표 원소 pa, pb를 뽑고, 둘 중 더 작은 쪽으로 parent[pa] or parent[pb]를 갱신

// 따라서 0 a b 꼴의 입력이 들어오면 union으로 합집합 연산하고, 1 a b 꼴이라면 a, b에 대해 find를 돌려 두 값이 일치하면 YES, 아니면 NO 출력하기