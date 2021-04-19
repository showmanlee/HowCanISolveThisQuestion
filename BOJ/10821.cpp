// 정수의 개수
// https://www.acmicpc.net/problem/10821

#include <iostream>
#include <string>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int res = 1;
	for (char c : s)
		if (c == ',')
			res++;
	cout << res << '\n';
}

// 문자열에 여러 개의 정수가 콤마로 구분되어 있을 때, 해당 문자열에 있는 정수의 개수는?
// 11,22,33,44 꼴을 유지하고 있음이 보장되어 있기에 굳이 토큰화하여 정수의 수를 셀 필요는 없음
// 콤마의 개수 + 1