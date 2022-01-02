// 패션왕 신해빈
// https://www.acmicpc.net/problem/9375

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		map<string, int> set;
		for (int i = 0; i < m; i++) {
			string a, b;
			cin >> a >> b;
			if (set.find(b) == set.end())
				set[b] = 1;
			else
				set[b]++;
		}
		int res = 1;
		for (auto k = set.begin(); k != set.end(); k++) 
			res *= k->second + 1;
		res--;
		cout << res << '\n';
	}
}

// 알몸이 아닌 입을 수 있는 최대 경우의 수
// 카테고리별로 수 + 1(안씀)씩 곱하고 1(알몸)을 뺌