// 등차수열에서 항 번호 찾기
// https://www.acmicpc.net/problem/14913

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, d;
	cin >> a >> b >> d;
	d -= a;
	if (d % b != 0 || (d / b + 1) <= 0) {
		cout << "X\n";
	} else {
		cout << (d / b + 1) << '\n';
	}
}

// 등차수열의 첫 항, 공차가 주어질 때, 주어진 수가 몇 번째 항인지 구하기(등차수열의 수가 아닐 수도 있음)

// 주어진 수에서 첫 항을 빼면 공차(의 곱)이 되더야 하는 수만 남을 테고, 그 수가 공차와 나누어떨어지면 등차수열의 수다 - 몫 + 1번째
// 다만 -n번째 항은 존재할 수 없으므로 주의할 것