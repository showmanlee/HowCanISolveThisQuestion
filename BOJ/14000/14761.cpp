// FizzBuzz
// https://www.acmicpc.net/problem/14761

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int x, y, n;
	cin >> x >> y >> n;
	for (int i = 1; i <= n; i++) {
		if (i % x == 0 || i % y == 0) {
			cout << (i % x == 0 ? "Fizz" : "") << (i % y == 0 ? "Buzz" : "") << '\n';
		}
		else {
			cout << i << '\n';
		}
	}
}

// x의 배수일 경우 Fizz, y의 배수일 경우 Buzz를 외치는 게임을 1부터 n까지 할 떄, 외치는 경우 출력하기

// 단순히 배수이기만 하면 되므로 반복문에 나머지를 넣어서 출력 가능
// 만약 배수가 둘 다 아니라면 숫자 출력하기