// CTP공국으로 이민 가자
// https://www.acmicpc.net/problem/12778

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<string, int> prs;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		char m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			if (m == 'C') {
				char p;
				cin >> p;
				cout << int(p - 'A' + 1) << ' ';
			}
			else {
				int p;
				cin >> p;
				cout << char(p + 'A' - 1) << ' ';
			}
		}
		cout << '\n';
	}
}

// 주어진 숫자를 알파벳으로 바꾸거나, 주어진 알파벳을 숫자로 바꾸기(1 <-> A)

// 어떻게 바꾸는지 보고, 주어진 문자들을 바꿔주면 됨 - 아스키 코드
// 여기서 숫자로 바꿀 때는 주어진 문자에서 1을 더해야 하고(0이 아닌 1부터 시작), 문자로 바꿀 때는 주어진 숫자에서 1을 빼야 함에 주의(숫자 + A = B부터 시작)