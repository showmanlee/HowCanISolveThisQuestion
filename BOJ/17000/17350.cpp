// 2루수 이름이 뭐야
// https://www.acmicpc.net/problem/17350

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	bool res = false;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "anj") {
			res = true;
		}
	}
	cout << "뭐야" << (res ? ";" : "?") << '\n';
}

// 영타로 친 한글 이름들이 주어질 때, '뭐'('anj')가 있는지 확인하기

// 확인해보세요 직접 - 포함이 아니라 딱 '뭐'면 됩니다