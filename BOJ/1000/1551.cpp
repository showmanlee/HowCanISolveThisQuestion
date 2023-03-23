// 수열의 변화
// https://www.acmicpc.net/problem/1551

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	stringstream ss(s);
	std::string p;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		getline(ss, p, ',');
		v[i] = stoi(p);
	}
	for (int t = 0; t < k; t++) {
		for (int i = 0; i < n - 1; i++) {
			v[i] = v[i + 1] - v[i];
		}
		n--;
	}
	for (int i = 0; i < n; i++) {
		cout << v[i] << (i == n - 1 ? '\n' : ',');
	}
}

// 주어진 수열에 v[i] = v[i + 1] - v[i]를 k번한 수열 구하기

// 다만 수열이 모두 붙어서 ,로 구분된 형태로 들어오는데 - 이 경우에는 stringstream을 만든 뒤 getline(ss, token, ',') 형태로 받아 쓸 수 있음
