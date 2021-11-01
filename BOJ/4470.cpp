// 줄번호
// https://www.acmicpc.net/problem/4470

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cin.ignore();
	for (int i = 1; i <= n; i++) {
		string s;
		getline(cin, s);
		cout << i << ". " << s << '\n';
	}
}

// 여러 줄의 문자열에서 각 줄 앞에 줄번호 붙이기

// 붙이면 됩니다 - getline을 활용하여