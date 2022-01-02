// 순열
// https://www.acmicpc.net/problem/9742

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	int n;
	while (cin >> s) {
		cin >> n;
		cout << s << ' ' << n << " = ";
		int p = 1;
		for (int i = 2; i <= s.length(); i++) {
			p *= i;
		}
		if (n > p) {
			cout << "No permutation\n";
			continue;
		}
		for (int i = 2; i <= n; i++) {
			next_permutation(s.begin(), s.end());
		}
		cout << s << '\n';
	}
}

// 사전 순으로 문자가 배치된 문자열로 만들 수 있는 순열 중 n번째 순열은?

// 문자열의 문자들이 사전 순으로 주어졌기 때문에 next_permutation을 n-1번 돌리면 된다 - 1번째는 돌리지 않은 원형
// 다만 n이 (길이!) 이하라는 것을 보장하지 않기에(길이에 관계없이 10!), 그 이상이 되는 경우 No permutation을 출력해야 함