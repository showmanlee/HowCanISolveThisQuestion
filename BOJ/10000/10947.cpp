// 모든 순열
// https://www.acmicpc.net/problem/10974

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		v[i] = i + 1;
	do {
		for (int i = 0; i < n; i++)
			cout << v[i] << ' ';
		cout << '\n';
	} while (next_permutation(v.begin(), v.end()));
}

// 1부터 n까지로 구성된 모든 순열을 사전 순으로 출력하기
// 재귀로도 풀 수 있지만, next_permutation을 통해서도 풀 수 있음
// 애초에 저 함수 자체가 이러라고 만들어진 것