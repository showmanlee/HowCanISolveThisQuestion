// 計算 (Calculation)
// https://www.acmicpc.net/problem/24075

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	cout << max(a - b, a + b) << '\n' << min(a - b, a + b) << '\n';
}

// 두 정수가 주어질 때, 두 수의 합과 차를 내림차순으로 출력하기

// min max 맞춰서 출력하면 됩니다...?