// 끝말잇기
// https://www.acmicpc.net/problem/20528

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	bool res = true;
	for (int i = 0; i < n - 1; i++)
		if (v[i][0] != v[i + 1][0])
			res = false;
	cout << res << '\n';
}

// 주어진 팰린드롬들로 끝말잇기가 가능한가?
// 팰린드롬은 앞으로 읽으나 뒤로 읽으나 똑같은 문자열 - 따라서 팰린드롬으로만 끝말잇기를 하려면 모든 팰린드롬의 끝 글자가 동일해야 함
// 입력된 문자열이 팰린드롬임이 보장되므로, 순서를 섞을 필요 없이 주어진 대로 내 첫글자와 다음 첫글자가 계속 동일한지만 체크하면 됨