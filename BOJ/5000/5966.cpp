// Cow Cotillion
// https://www.acmicpc.net/problem/5966

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		string s;
		cin >> n >> s;
		bool minus = false;
		int cnt = 0;
		for (char c : s) {
			cnt += (c == '>' ? 1 : -1);
			if (cnt < 0) {
				minus = true;
			}
		}
		cout << (cnt == 0 && !minus ? "legal" : "illegal") << '\n';
	}
}

// 주어진 문자열에서 >< 쌍이 맞는지 확인하기

// 문자만 바뀌었을 뿐, 괄호 스택 문제임 - 스택이 0인 상태에서 더 닫히면 안 되는 것도 동일
// 단순 괄호 판정 문제의 경우 스택이 아닌 카운터+minus 판정 변수로도 계산할 수 있다