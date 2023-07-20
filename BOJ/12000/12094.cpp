// A와 B
// https://www.acmicpc.net/problem/12904

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	string s, t;
	cin >> s >> t;
	while (s.length() < t.length()) {
		char c = t.back();
		t.pop_back();
		if (c == 'B') {
			reverse(t.begin(), t.end());
		}
	}
	cout << (s == t) << '\n';
}

// A와 B로만 구성된 문자열에서 뒤에 A 붙이기, 뒤집고 뒤에 B 붙이기 만으로 다른 문자열을 만들 수 있는지 확인하기

// 정방향으로 탐색(BFS 등)하려면 시간이 오래 걸림 - 하지만 역방향으로 돌리면 단방향으로 해결 가능
// 어차피 문자는 뒤로 계속 붙고, 마지막 문자에 따라 나머지 문자열을 뒤집을지만 보면 되기 때문
// 따라서 마지막 문자를 계속 빼면서 문자열을 변형하다가, 두 문자열의 길이가 같아졌을 때 서로 같은지 확인하면 됨