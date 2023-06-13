// Not A + B
// https://www.acmicpc.net/problem/23530

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int a, b;
		cin >> a >> b;
		cout << 1 << '\n';
	}
}

// 1부터 50까지의 수 a, b가 주어질 때, 1부터 50까지의 수 중 a+b가 아닌 수 c 구하기

// 자연수 a, b의 합은 절대 1이 될 수 없음