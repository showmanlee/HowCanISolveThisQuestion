// 집합
// https://www.acmicpc.net/problem/11723

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr = 0b000000000000000000000;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		int t = 0;
		cin >> s;
		if (s == "add") {
			cin >> t;
			arr |= 1 << t;
		}
		else if (s == "remove") {
			cin >> t;
			arr &= ~(1 << t);
		}
		else if (s == "check") {
			cin >> t;
			cout << (arr >> t) % 2 << '\n';
		}
		else if (s == "toggle") {
			cin >> t;
			if ((arr >> t) % 2 == 0)
				arr |= 1 << t;
			else
				arr &= ~(1 << t);
		}
		else if (s == "all") {
			arr = 0b111111111111111111111;
		}
		else if (s == "empty") {
			arr = 0b000000000000000000000;
		}
	}
}

// 원소 수는 최대 20개
// 있냐 없냐로 구분하니까 비트마스킹으로 풀 수 있다고 - 어차피 메모리도 극단적으로 작게 주어짐