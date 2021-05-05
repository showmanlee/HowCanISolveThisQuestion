// 1
// https://www.acmicpc.net/problem/4375

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	while (cin >> n) {
		int p = 1;
		int res = 1;
		while (true) {
			if (p % n == 0) {
				cout << res << '\n';
				break;
			}
			p = p * 10 + 1;
			p %= n;
			res++;
		}
	}
}

// 2와 5로 나누어떨어지지 않는 n의 배수 중 1로만 구성된 가장 작은 자연수의 길이는?
// 1로만 구성된 수를 늘여가며 n으로 나누어떨어지는지 확인하면 됨 - 물론 무식하게 해서는 안됨
// 나머지 연산을 할 정수와 길이를 나타내는 정수를 분리 - 다음 길이를 찾을 때 길이는 +1, 나머지는 (* 10 + 1) % n
// 이를 반복하다보면 반드시 p % n == 0인 경우가 있음 - 이때 길이 출력하기
// 입력값 범위 안에 1이 들어가 있음에 주의 - % n == 0 판정을 먼저
// 명확한 입력 종료가 주어지지 않음에 주의 - while(cin >> n)