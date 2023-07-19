// Multiple Choice
// https://www.acmicpc.net/problem/6784

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<char> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (v[i] == c) {
			res++;
		}
	}
	cout << res << '\n';
}

// 5지선다 객관식 문제 n개의 답안과 정답이 주어질 때, 맞은 문제 수 출력하기

// == count
