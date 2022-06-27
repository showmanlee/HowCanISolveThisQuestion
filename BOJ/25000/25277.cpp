// Culture shock
// https://www.acmicpc.net/problem/25277

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "he" || s == "she" || s == "him" || s == "her") {
			res++;
		}
	}
	cout << res << '\n';
}

// 주어진 문자열에 3인칭 대명사(he, she, him, her)가 몇 개 등장하는지 확인하기

// 처음에 단어 수가 주어지므로, getline 없이 파악 가능