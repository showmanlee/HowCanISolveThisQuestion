// 周期文字列 (Cycle String)
// https://www.acmicpc.net/problem/33172

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;
	bool res = false;
	for (int i = 1; i <= n / 2; i++) {
		if (n % i == 0) {
			bool pass = true;
			string ss = s.substr(0, i);
			for (int j = i; j < n; j += i) {
				string sss = s.substr(j, i);
				if (ss != sss) {
					pass = false;
					break;
				}
			}
			if (pass) {
				res = true;
				break;
			}
		}
	}
	cout << (res ? "Yes" : "No") << '\n';
}

// 주어진 문자열을 2번 이상 반복되는 부분 문자열로 나눌 수 있는지 구하기