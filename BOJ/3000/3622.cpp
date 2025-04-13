// 어떤 호박의 할로윈 여행
// https://www.acmicpc.net/problem/3622

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A, a, B, b, p;
	cin >> A >> a >> B >> b >> p;
	bool res = false;
	if (A + B <= p) {
		res = true;
	} else if (p >= A && a >= B) {
		res = true;
	} else if (p >= B && b >= A) {
		res = true;
	}
	cout << (res ? "Yes" : "No") << '\n';
}

// 8*8 보드에서 n개의 돌이 놓인 위치가 주어질 때, 가장 많은 돌이 있는 열의 돌 개수 구하기