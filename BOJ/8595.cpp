// 히든 넘버
// https://www.acmicpc.net/problem/8595

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n;
	string s;
	cin >> n >> s;
	long long res = 0;
	string hidden = "";
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			hidden += s[i];
		}
		else if (hidden != "") {
			res += stoi(hidden);
			hidden = "";
		}
	}
	if (hidden != "") {
		res += stoi(hidden);
		hidden = "";
	}
	cout << res << '\n';
}

// 간단하지만 문자열의 길이가 최대 5000000. 극단적인 경우 int 범위를 벗어날 수 있기 때문에 long long으로 합산값을 처리해야 함
// 문자열의 모든 문자를 탐색하며 숫자가 있으면 가져오고, 숫자가 끝나면 해당 값을 int로 바꾸어 더해주기
// 6자리 제한이 있긴 하지만 여기서 잡아줄 필요는 없음