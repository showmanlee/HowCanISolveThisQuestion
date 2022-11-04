// 최대 GCD
// https://www.acmicpc.net/problem/9417

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (a < b)
		swap(a, b);
	while (b != 0) {
		int p = a % b;
		a = b;
		b = p;
	}
	return a;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	cin.ignore();

	for (int t = 0; t < tt; t++) {
		string s;
		getline(cin, s);
		vector<int> v;
		stringstream ss(s);
		int p;
		while (ss >> p) {
			v.push_back(p);
		}
		int res = 0;
		for (int i = 0; i < v.size() - 1; i++) {
			for (int j = i + 1; j < v.size(); j++) {
				res = max(res, gcd(v[i], v[j]));
			}
		}
		cout << res << '\n';
	}
}

// 주어진 수들 중 두 개를 골라 만들 수 있는 최대공약수 중 가장 큰 수는?

// 전체 쌍을 구해도 시간이 충분하니 전체 쌍을 구해서 큰 값을 찾자
// 한 테케당 수들이 개수 명시 없이 한 줄로 주어짐에 주의 - stringstream 파싱 필요