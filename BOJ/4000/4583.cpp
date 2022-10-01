// 거울상
// https://www.acmicpc.net/problem/4583

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		string s;
		cin >> s;
		if (s == "#") {
			break;
		}
		string res;
		for (char c : s) {
			if (c == 'b') {
				res = 'd' + res;
			} else if (c == 'd') {
				res = 'b' + res;
			} else if (c == 'p') {
				res = 'q' + res;
			} else if (c == 'q') {
				res = 'p' + res;
			} else if (c == 'i' || c == 'o' || c == 'v' || c == 'w' || c == 'x') {
				res = c + res;
			} else {
				res = "INVALID";
				break;
			}
		}
		cout << res << '\n';
	}
}

// 소문자로 주어진 문자열을 좌우반전했을 때도 소문자로 나타낼 수 있다면 출력하기

// 각 문자를 돌면서 맨 뒤부터 b-d, p-q와 반대 쌍으로, iovwx는 그대로 출력한다
// 만약 도는 과정 중 위의 글자가 안 나오면 INVALID 처리하고 바로 탈출