// 링
// https://www.acmicpc.net/problem/3036

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (a < b)
		swap(a, b);
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i < n; i++) {
		int p = gcd(v[0], v[i]);
		cout << (v[0] / p) << '/' << (v[i] / p) << '\n';
	}
}

// 서로 맞닿아있는 바퀴들 중 첫 번째 바퀴를 한 바퀴 돌릴 때, 나머지 바퀴들이 돌아가는 바퀴 수를 기약분수로 출력하기

// 어떤 바퀴가 돌아가는 바퀴 수는 첫 바퀴 크기 / 어떤 바퀴 크기
// 그리고 이걸 기약분수로 만드는 건 양 변을 최대공약수로 나눠주는 것