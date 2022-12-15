// 삼각 무늬 - 2
// https://www.acmicpc.net/problem/11312

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		long long a, b;
		cin >> a >> b;
		long long p = a / b;
		cout << (p * p) << '\n';
	}
}

// 큰 정삼각형과 작은 정삼각형들의 변의 길이가 주어졌을 때, 작은 정삼각형으로 큰 정삼각형을 덮는데 필요한 삼각형의 개수 구하기

// 정삼각형 변의 길이는 서로 나누어떨어지는 것이 보장되므로, 한 변을 채우는데 필요한 정삼각형의 개수는 a / b가 된다
// 이 상황에서 규칙을 찾아보면 1 -> 4 -> 9 -> 16... - 제곱수임
// 그렇게 출력해주면 됩니다...
// 삼각 무늬 1과 같은 문제 - 범위가 100만이니 long long만 신경써주면 됨...