// 이름궁합 테스트
// https://www.acmicpc.net/problem/17269

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	string row = "32124313113132122212111221";
	int n, m;
	string a, b;
	cin >> n >> m;
	cin >> a >> b;
	int i = 0, j = 0;
	vector<int> v;
	while (i < n || j < m) {
		if (i < n) {
			v.push_back(row[a[i] - 'A'] - '0');
			i++;
		}
		if (j < m) {
			v.push_back(row[b[j] - 'A'] - '0');
			j++;
		}
	}
	for (int p = n + m - 1; p >= 2; p--) {
		for (int t = 0; t < p; t++)
			v[t] = (v[t] + v[t + 1]) % 10;
	}
	int res = v[0] * 10 + v[1];
	cout << res << '%' << '\n';
}

// 알파벳을 받아 이름궁합 테스트를 보자!
// v[i] = v[i] + v[i+1]을 2개 남을 때까지 반복