// Figure Skating
// https://www.acmicpc.net/problem/20218

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	map<string, int> v;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v[s] = i;
	}
	int res = 0;
	string ress;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int p = v[s] - i;
		if (res < p) {
			ress = s;
			res = p;
		}
	}
	cout << (ress == "" ? "suspicious" : ress) << '\n';
}

// 변동이 있는 두 순위표에서 순위 변화가 가장 높은 선수 구하기