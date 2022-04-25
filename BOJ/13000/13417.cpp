// 카드 문자열
// https://www.acmicpc.net/problem/13417

#include <iostream>
#include <vector>
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
		cin >> n;
		vector<char> cards(n);
		for (int i = 0; i < n; i++) {
			cin >> cards[i];
		}
		string res;
		res += cards[0];
		for (int i = 1; i < n; i++) {
			if (cards[i] <= res[0]) {
				res = cards[i] + res;
			}
			else {
				res = res + cards[i];
			}
		}
		cout << res << '\n';
	}
}

// 알파벳이 적힌 카드들을 순서대로 맨 앞이나 뒤에 붙여가며 문자열을 만들 떄 만들 수 있는 사전 상 가장 앞선 문자열은?

// 먼저 첫 문자를 문자열에 가져온다
// 이후 두 번째 문자부터 문자열 맨 앞과 비교하면서 문자가 앞서거나 같으면 앞에, 아니면 뒤에 붙인다 