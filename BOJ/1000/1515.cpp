// 수 이어 쓰기
// https://www.acmicpc.net/problem/1515

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int idx = 0;
	int n = 0;
	while (idx < s.length()) {
		n++;
		string ns = to_string(n);
		for (int i = 0; i < ns.length(); i++) {
			if (s[idx] == ns[i]) {
				idx++;
				continue;
			}
		}
	}
	cout << n << '\n';
}

// 1부터 어떤 수까지 이어 쓴 문자열에서 글자를 지운 결과가 주어질 떄, 어떤 수의 최솟값 출력하기