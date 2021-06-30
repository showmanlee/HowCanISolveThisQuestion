// 등장하지 않는 문자의 합
// https://www.acmicpc.net/problem/3059

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		vector<bool> shown(26);
		for (char c : s)
			shown[c - 'A'] = true;
		int res = 0;
		for (int t = 0; t < 26; t++)
			if (!shown[t])
				res += t + 65;
		cout << res << '\n';
	}
}

// 대문자 문자열에서 등장하지 않는 대문자의 아스키 코드 합은?

// 주어진 문자열에서 등장하지 않은 문자를 배열을 통해 체크해준 뒤, 등장하지 않은 문자에 해당되는 아스키 코드 값을 모두 더한다