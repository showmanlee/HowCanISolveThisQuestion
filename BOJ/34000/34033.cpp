// 공금 횡령
// https://www.acmicpc.net/problem/34033

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	map<string, int> prices;
	for (int i = 0; i < n; i++) {
		string s;
		int p;
		cin >> s >> p;
		prices[s] = p;
	}
	int res = 0;
	for (int i = 0; i < m; i++) {
		string s;
		int p;
		cin >> s >> p;
		if (p > prices[s] * 1.05) {
			res++;
		}
	}
	cout << res << '\n';
}

// 주어진 내역의 구매가가 원가의 1.05배를 넘는 횟수 구하기