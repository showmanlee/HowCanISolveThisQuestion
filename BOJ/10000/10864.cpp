// 친구
// https://www.acmicpc.net/problem/10864

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int n, m;
	cin >> n >> m;
	vector<int> res(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		res[a]++;
		res[b]++;
	}
	for (int i = 1; i <= n; i++) {
		cout << res[i] << '\n';
	}
}

// n명의 친구 관계가 주어질 때, 각각의 친구 수 출력하기

// 한번 주어진 관계는 중복해서 주어지지 않음이 보장되므로, 숫자들이 나온 횟수가 곧 친구(관계) 수라고 할 수 있음
// 따라서 배열도 2차원으로 펼쳐주는 대신 1차원으로만 펼쳐줘도 됨