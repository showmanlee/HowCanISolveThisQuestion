// 도비의 영어 공부
// https://www.acmicpc.net/problem/2386

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		string l, s;
		cin >> l;
		if (l == "#")
			break;
		getline(cin, s);
		int res = 0;
		for (char c : s) {
			if (c == l[0] || c == l[0] + 'A' - 'a')
				res++;
		}
		cout << l << ' ' << res << '\n';
	}
}

// 한 알파벳이 다음 문자열에 얼마나 나오는가?
// 문자는 >>으로 받고, 그 다음 띄어쓰기 포함한 문자열은 getline으로 받는다 - 이미 cin 스트림이 하나를 읽었기에 getline을 쓰면 그 이후부터 읽는다
// 소문자로 대문자까지 잡아내야 함에 주의