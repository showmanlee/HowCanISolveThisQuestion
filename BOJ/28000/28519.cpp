// Планеты двух измерений
// https://www.acmicpc.net/problem/28519

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	if (a != b) {
		cout << (min(a, b) * 2 + 1) << '\n';
	} else {
		cout << (a * 2) << '\n';
	}
}

// 왼쫙 a개와 오른쪽 b개를 서로 번갈아가며 고르는 최대 길이 구하기