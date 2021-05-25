// 보너스 점수
// https://www.acmicpc.net/problem/17389

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
	int res = 0, combo = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'O') {
			res += i + 1 + combo;
			combo++;
		}
		else
			combo = 0;
	}
	cout << res << '\n';
}

// i번 문제를 맞추면 i점을 주는 OX퀴즈에서 연속으로 문제를 맞추면 (연속으로 맞춘 점수 - 1)만큼의 추가 점수를 얻을 수 있을 때, 얻는 점수는?

// 콤보 카운터는 0부터 시작
// 이후 모든 문자를 순회하면서 O라면 해당 인덱스 번호 + 콤보를 점수에 추가하고 콤보를 늘린다
// X라면 점수를 추가하지 않고 콤보를 0으로 맞춘다
// 이 과정을 마친 후 최종 점수를 출력하기