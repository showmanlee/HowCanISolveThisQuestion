// 합 구하기
// https://www.acmicpc.net/problem/11441

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		v[i] = v[i - 1] + p;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << (v[b] - v[a - 1]) << '\n';
	}
}

// 정수 배열이 주어졌을 때, a번째에서 b번째 수까지의 합 구하기

// 당연히 누적합 배열을 만들어서 풀어야 함 - 기본적인 누적합 연습 문제
// 각 칸에는 해당 수까지의 합을 저장하고, 구간이 주어졌을 때 b에서 a-1 뺴기