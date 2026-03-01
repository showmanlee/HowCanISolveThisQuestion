// 합의 최소
// https://www.acmicpc.net/problem/33910

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	long long minn = 987654321;
	long long res = 0;
	for (int i = n - 1; i >= 0; i--) {
		minn = min(minn, v[i]);
		res += minn;
	}
	cout << res << '\n';
}

// 수열에서 자신과 앞 원소 중 작은 원소로 자신을 바꿀 수 있을 때, 수열의 최소 합 구하기