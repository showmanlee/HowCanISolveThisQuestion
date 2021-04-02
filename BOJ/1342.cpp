// 행운의 문자열
// https://www.acmicpc.net/problem/1342

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	int n = s.length();
	int res = 0;
	do {
		bool flag = false;
		for (int i = 0; i < n - 1; i++) {
			if (s[i] == s[i + 1]) {
				flag = true;
				break;
			}
		}
		if (!flag)
			res++;
	} while (next_permutation(s.begin(), s.end()));
	cout << res << '\n';
}

// 주어진 문자열을 재조합했을 때 같은 문자가 연속되지 않는 경우의 수는?
// 문자열 길이가 10 이하다 - 브포 적용 가능!
// 정확히는 문자열을 순열하는 것 - next_permutation
// 여기서 양옆의 문자열이 같지 않은 결과만 나온 경우 결과값에 추가