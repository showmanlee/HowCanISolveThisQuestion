// 캥거루 세마리 2
// https://www.acmicpc.net/problem/11034

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int a, b, c;
	while (cin >> a >> b >> c) {
		int res = max(b - a, c - b) - 1;
		cout << res << '\n';
	}
}

// 1차원 정수 좌표에서 세 점 중 하나를 나머지 두 점 사이로만 옮길 수 있을 때, 최대로 옮길 수 있는 횟수 구하기

// 둘 중 차이가 더 큰 쪽에 점을 하나씩 다른 점에 최대한 붙이면 됨
// 따라서 둘 중 더 큰 공간 - 1