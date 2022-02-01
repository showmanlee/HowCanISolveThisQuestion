// 중앙 이동 알고리즘
// https://www.acmicpc.net/problem/2903

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int p = 2;
	for (int i = 0; i < n; i++) {
		p += p - 1;
	}
	cout << (p * p) << '\n';
}

// 각 꼭지점에 점이 찍힌 정사각형의 각 변 중앙과 중심에 점을 찍는 과정을 새로 생긴 정사각형들에 n번 반복할 때, 나올 수 있는 점의 개수는?

// 변의 점 개수는 반복이 1회 늘어날 때마다 p - 1개씩 늘어난다 - 그리고 점의 개수는 그거의 제곱