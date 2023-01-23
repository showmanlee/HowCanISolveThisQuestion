// Робинзон Крузо
// https://www.acmicpc.net/problem/27219

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n / 5; i++) {
		cout << "V";
	}
	for (int i = 0; i < n % 5; i++) {
		cout << "I";
	}
	cout << '\n';
}

// 주어진 숫자를 I와 V만을 이용하여 로마 숫자로 출력하기

// 정확히 말하면 5로 나눈 몫을 V, 나머지를 I로 쓰자는 것 - 쓰면 되지요