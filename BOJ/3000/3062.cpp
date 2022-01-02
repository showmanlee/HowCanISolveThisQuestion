// 수 뒤집기
// https://www.acmicpc.net/problem/3062

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
		string s;
		cin >> s;
		int a = stoi(s);
		reverse(s.begin(), s.end());
		int b = stoi(s);
		string p = to_string(a + b);
		bool res = true;
		for (int i = 0; i < p.length() / 2; i++)
			if (p[i] != p[p.length() - i - 1])
				res = false;
		cout << (res ? "YES\n" : "NO\n");
	}
}

// 어떤 수를 바로 놓은 모양과 뒤집어 놓은 모양을 더한 수가 좌우 대칭이 되는지 판별하기

// 정수를 문자열로 받아 정수화 한 것을 저장하고, 그 문자열을 뒤집어 정수화한 것을 다시 저장한다
// 그리고 그 두 정수의 합을 문자열화하여 좌우 대칭 여부를 판별하기