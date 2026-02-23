// Presidents
// https://www.acmicpc.net/problem/26562

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		int res = 0;
		string s, t;
		getline(cin, s);
		stringstream ss(s);
		while (ss >> t) {
			if (t == "Franklin") {
				res += 100;
			} else if (t == "Grant") {
				res += 50;
			} else if (t == "Jackson") {
				res += 20;
			} else if (t == "Hamilton") {
				res += 10;
			} else if (t == "Lincoln") {
				res += 5;
			} else if (t == "Washington") {
				res += 1;
			}
		}
		cout << "$" << res << '\n';
	}
}

// 한 줄에 주어진 단어들 중 가장 많이 나온 단어의 첫 글자 출력하기