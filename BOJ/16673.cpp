// 고려대학교에는 공식 와인이 있다
// https://www.acmicpc.net/problem/16673

#include <iostream>
using namespace std;

int main(void) {
	int c, k, p, answer = 0;
	cin >> c >> k >> p;
	for (int i = 1; i <= c; i++)
		answer += k * i + p * i * i;
	cout << answer << endl;
}

// int로도 충분히 가능