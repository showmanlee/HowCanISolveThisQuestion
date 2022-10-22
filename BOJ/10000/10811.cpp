// 바구니 뒤집기
// https://www.acmicpc.net/problem/10811

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		v[i] = i;
	}
	for (int t = 0; t < m; t++) {
		int a, b;
		cin >> a >> b;
		reverse(v.begin() + a, v.end() - n + b);
	}
	for (int i = 1; i <= n; i++) {
		cout << v[i] << ' ';
	}
	cout << '\n';
}

// 순서대로 수가 나열된 자연수 배열에서 특정 범위의 순서를 뒤집는 과정을 반복한 후의 배열 상태 출력하기

// vector(의 일부 범위) 뒤집기는 reverse - 확실하게 끝점을 두고 싶다면 end - n + 끝점
// 이렇게 reverse를 반복해주면 됩니다...