// 라면 끓여 먹자 야호
// https://www.acmicpc.net/problem/34687

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	float a, b;
	cin >> a >> b;
	cout << (a * 0.81f <= b ? "yaho" : "no") << '\n';
}

// fizzbuzz를 임의의 수 a, b로 1부터 n까지 한 결과 출력하기