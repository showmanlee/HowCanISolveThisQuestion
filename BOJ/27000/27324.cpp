// ゾロ目 (Same Numbers)
// https://www.acmicpc.net/problem/27324

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	cout << (n / 10 == n % 10) << '\n';
}

// 주어진 두자릿수의 십의 자리와 일의 자리 숫자가 같은지 확인하기

// 그럴게요, 이렇게 하면 되나요?