// f(A + B)
// https://www.acmicpc.net/problem/32748

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<char> v(10), w(10);
	for (int i = 0; i < 10; i++) {
		cin >> v[i];
		w[v[i] - '0'] = i + '0';
	}
	string a, b;
	cin >> a >> b;
	string aa, bb;
	for (char c : a) {
		aa += w[c - '0'];
	}
	for (char c : b) {
		bb += w[c - '0'];
	}
	string ab = to_string(stoi(aa) + stoi(bb));
	string res;
	for (char c : ab) {
		res += v[c - '0'];
	}
	cout << res << '\n';
}

// 각 숫자를 다른 숫자로 대응하는 함수 f에 대해 f(A), f(B)가 주어질 떄, f(A + B) 구하기