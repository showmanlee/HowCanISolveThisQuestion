// 팩토리얼
// https://www.acmicpc.net/problem/7489

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		long long res = 1;
		for (int i = 1; i <= n; i++) {
			res *= i;
			while (res % 10 == 0)
				res /= 10;
			res %= 100000000;
		}
		cout << (res % 10) << '\n';
	}
}

// 팩토리얼에서 0이 아닌 최우측 수 구하기

// 2553 마지막 팩토리얼 수와 같은 문제 - 범위가 더 작긴 하지만 엄청난 팩토리얼이라는 것은 똑같음
// 따라서 원리도 같음 - 각 단계의 팩토리얼을 구하면서 뒤의 0들은 모두 제거해둔다
// 저 문제와 똑같이 팩토리얼 결과를 한자릿수로 만들어주면 안 됨 - 계산 결과로 0이 붙는 경우 문제 발생 (15! = ...12 * 15 = 18(0), ...2 * 15 = 3(0)??)
// 따라서 중간 결과 저장을 여유롭게 걸어줘야 함 - 결과 저장 변수를 long long으로 선언하여 여유롭게 나머지 연산
// 물론 마지막에는 % 10으로 출력해야 함