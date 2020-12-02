// 별 찍기 - 12
// https://www.acmicpc.net/problem/2522

#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int i = n - 1; i >= -n + 1; i--) {
		for (int j = 0; j < abs(i); j++)
			cout << ' ';
		for (int j = n; j > abs(i); j--)
			cout << '*';
		cout << '\n';
	}
}

// 별 찍기 문제는 컴퓨터적 사고 향상에 도움을 줍니다