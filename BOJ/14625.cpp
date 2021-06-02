// 냉동식품
// https://www.acmicpc.net/problem/14625

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int sh, sm, gh, gm, n;
	cin >> sh >> sm >> gh >> gm >> n;
	int res = 0;
	while (true) {
		if (sh % 10 == n || sh / 10 == n || sm % 10 == n || sm / 10 == n)
			res++;
		if (sh == gh && sm == gm)
			break;
		sm++;
		if (sm == 60) {
			sm = 0;
			sh++;
		}
	}
	cout << res << '\n';
}

// 시작 시간부터 종료 시간까지 타이머를 돌릴 때, 숫자 n이 등장하는 시각의 개수는?

// 시작 시간부터 종료 시간까지 시간을 흘려주면서, 숫자가 나오면 결과을 추가해주기
// 시작 시간과 종료 시간을 모두 포함하기 위해 판정 -> 종료 -> 증가 순으로 반복문 진행하기
// 숫자 n이 등장하는 횟수가 아닌, 등장하는 시각의 횟수임에 주의 - 여러 개 나와도 1개씩 카운트