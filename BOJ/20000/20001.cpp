// 고무오리 디버깅
// https://www.acmicpc.net/problem/20001

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	int st = 0;
	getline(cin, s);
	while (true) {
		getline(cin, s);
		if (s == "고무오리 디버깅 끝")
			break;
		else if (s == "문제")
			st++;
		else if (s == "고무오리") {
			if (st == 0)
				st += 2;
			else
				st--;
		}
	}
	cout << (st == 0 ? "고무오리야 사랑해" : "힝구") << '\n';
}

// 신비한 고무오리는 부르면 풀고 있던 문제 중 하나를 풀어주지만, 문제가 없을 때 부르면 문제 2개를 추가한다. 고무오리로 문제를 모두 풀 수 있는가?
// "문제"를 외치면 문제가 하나 쌓인다
// "고무오리"를 외쳤을 때 문제가 없다면 문제 2개가 추가되고, 그렇지 않으면 문제가 하나 줄어든다
// 마지막으로 "고무오리 디버깅 끝"을 외쳤을 때 문제가 남았다면 "힝구", 그렇지 않다면 "고무오리야 사랑해"를 외친다