// 경로당펑크 2077
// https://www.acmicpc.net/problem/25205

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;
	switch (s[n - 1]) {
		case 'y':
		case 'u':
		case 'i':
		case 'o':
		case 'p':
		case 'h':
		case 'j':
		case 'k':
		case 'l':
		case 'b':
		case 'n':
		case 'm':
			cout << "0\n";
			break;
		default:
			cout << "1\n";
			break;
	}
}

// 플레이어 이름을 영타로 친 결과가 주어질 때, 해당 이름에 받침이 있는지 판정하기

// 이 문제에서는 겹받침이나 이중모음이 등장하지 않음 - 그리고 타이핑 오류를 판정할 필요도 없음
// 따라서 뒤에 모음이 나오냐 안 나오냐만 보면 판정 가능