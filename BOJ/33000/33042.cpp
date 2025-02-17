// 이변마작 1
// https://www.acmicpc.net/problem/33042

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
	map<string, int> cnt;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		cnt[s]++;
		if (res == 0 && cnt[s] >= 5) {
			res = i;
		}
	}
	cout << res << '\n';
}

// 주어지는 문자열 중 똑같은 문자열이 5번째로 등장하는 위치 찾기