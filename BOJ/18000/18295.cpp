// Ants
// https://www.acmicpc.net/problem/18295

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	long long res = 0;
	map<string, bool> v;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s[0] == '-') {
			continue;
		}
		v[s] = true;
		if (s.length() <= 8 && res == stoll(s)) {
			for (long long i = res + 1; ; i++) {
				if (!v[to_string(i)]) {
					res = i;
					break;
				}
			}
		}
	}
	cout << res << '\n';
}

// 주어지는 정수들에서 음수를 제외할 떄, 나오지 않은 정수 중 가장 작은 수 구하기