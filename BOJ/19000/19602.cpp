// Dog Treats
// https://www.acmicpc.net/problem/19602

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int s, m, l;
	cin >> s >> m >> l;
	int res = s + m * 2 + l * 3;
	cout << (res >= 10 ? "happy" : "sad") << '\n';
}

// s, m, l이 주어질 때, s * 1 + m * 2 + l * 3이 10 이상인지 확인하기

// 계산해보면 되지요