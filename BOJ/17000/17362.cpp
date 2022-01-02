// 수학은 체육과목 입니다 2
// https://www.acmicpc.net/problem/17362

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	n--;
	if (n / 4 % 2 == 0) {
		cout << (n % 4 + 1) << '\n';
	}
	else {
		cout << (5 - (n % 4)) << '\n';
	}
}

// 엄지~새끼손가락의 번호를 1~5라고 두고, 1부터 n까지 1번 손가락부터 왕복하며 셀 때, n번을 셀 때는 몇번 손가락에 위치하는가?
// n에서 1을 빼서 나머지 연산을 직관적으로 만든 후, n / 2가 짝수인 경우에는 n % 4에 따라 1~4번을, 홀수라면 5~2를 출력하도록 설정