// 현실적인 생일 축하 방안
// https://www.acmicpc.net/problem/33664

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long b;
	int n, m;
	cin >> b >> n >> m;
	map<string, long long> v;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		cin >> v[s];
	}
	long long res = 0;
	for (int j = 0; j < m; j++) {
		string s;
		cin >> s;
		res += v[s];
	}
	cout << (res <= b ? "acceptable" : "unacceptable") << '\n';
}

// 가격이 주어진 n개의 상품 중 m개의 상품을 구입했을 때 예산 안에 들어가는지 구하기