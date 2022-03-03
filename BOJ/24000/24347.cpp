// КАРТИ
// https://www.acmicpc.net/problem/24347

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<string> s(4);
	for (int i = 0; i < 4; i++) {
		cin >> s[i];
	}
	sort(s.begin(), s.end());
	long long res = 0;
	do {
		string r = s[0] + s[1] + s[2] + s[3];
		if (stoll(r) > res) {
			res = stoll(r);
		}
	} while (next_permutation(s.begin(), s.end()));
	cout << res << '\n';
}

// 4개의 수가 적힌 카드를 이어붙여서 만들 수 있는 가장 큰 숫자는?

// 수가 4개만 주어지므로 모든 조합을 찾아볼 수 있음
// 적어도 하나의 카드는 0이 아님이 보장되기에 앞에 붙는 0을 고려할 필요도 없음 - 앞에 0이 붙으면 무조건 답이 될 수 없음