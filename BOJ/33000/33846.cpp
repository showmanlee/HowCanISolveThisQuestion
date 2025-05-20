// 삽입 정렬을 해볼까
// https://www.acmicpc.net/problem/33846

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, t;
	cin >> n >> t;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.begin() + t);
	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}
	cout << '\n';
}

// 주어진 배열을 t번째 칸까지 정렬하기