// Back to Origin
// https://www.acmicpc.net/problem/34530

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int p = 360;
	while (true) {
		if (p % n == 0) {
			cout << (p / n) << '\n';
			break;	
		}
		p += 360;
	}
}

// 평면에서 1km 이동 후 n도 회전을 반복할 때, 출발점으로 정확히 돌아오는 이동 횟수 구하기