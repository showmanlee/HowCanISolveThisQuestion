// 팰린드롬 척화비
// https://www.acmicpc.net/problem/20944

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << 'a';
	}
	cout << '\n';
}

// 길이가 n이며 앞쪽 절반이 뒤쪽 절반과 같은 팰린드롬 구하기

// 어렵게 생각할 필요 없음 - 같은 글자로 구성되면 그게 수미상관이며 팰린드롬이지
// 자리가 길어지면 구하기 어려워질 수밖에 없음 - 그러니 쉬운 방법으로 돌아가면 되지