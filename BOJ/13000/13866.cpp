// 팀 나누기
// https://www.acmicpc.net/problem/13866

#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	cout << abs((a + d) - (b + c)) << '\n';
}

// 네 명의 능력치가 주어질 때, 두 팀의 능력치의 차가 최소가 되도록 한 경우의 차 출력하기
// a b c d는 모두 정렬된 상태 - 그리고 두 팀의 능력치의 차를 최소화하려면 a + d와 b + c로 나누면 됨
// 이 두 값의 차의 절댓값이 결과값