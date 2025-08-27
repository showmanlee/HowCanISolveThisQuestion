// Making Change
// https://www.acmicpc.net/problem/27106

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	n = 100 - n;
	vector<int> v = {25, 10, 5, 1};
	vector<int> res(4);
	for (int i = 0; i < 4; i++) {
		res[i] = n / v[i];
		n %= v[i];
	}
	for (int i = 0; i < 4; i++) {
		cout << res[i] << ' ';
	}
	cout << '\n';
}

// 주어진 센트를 달러로 바꾸기 위해 들여야 하는 동전 갯수 구하기