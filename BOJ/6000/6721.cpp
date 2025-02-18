// Backward numbers
// https://www.acmicpc.net/problem/6721

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		string a, b;
		cin >> a >> b;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int p = stoi(a) + stoi(b);
		string r = to_string(p);
		reverse(r.begin(), r.end());
		int res = stoi(r);
		cout << res << '\n';
	}
}

// 주어진 두 정수의 숫자 순서를 뒤집어서 더한 후 그 결과의 숫자 순서를 다시 뒤집은 결과 출력하기