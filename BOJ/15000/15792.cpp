// A/B - 2
// https://www.acmicpc.net/problem/15792

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	cout << (a / b) << '.';
	a = a % b;
	for (int i = 0; i < 1000; i++) {
		a *= 10;
		cout << a / b;
		a = a % b;
	}
}

// A/B의 결과를 소수점 아래 1000자리까지 출력하기

// 어떤 언어도 기본 나눗셈으로 시간 제한 안에 1000자리까지 출력할 수 없음 - C++은 당연하고
// 그래서 발상의 전환이 필요함 - 우리가 손으로 나눗셈을 하는 방식을 대입한다
// 어떻게 위 식이 나오는 걸까? - 10 / 7을 예로 들어봅시다
// 우선 10 / 7 = 3 ... 3
// 여기서 나머지 3을 7로 나눠야 하는데, 이러면 1 미만의 소수가 나오므로 10을 곱해 맨 앞의 수를 해당 소수점 첫 자리로 삼는다(10을 곱한 수를 b로 나눠도 언제나 결과는 10 미만이므로)
// 따라서 3 * 10 / 7 = 4 ... 2
// 그 뒤로도 계속 나머지를 구하며 같은 방식으로 반복하면 된다