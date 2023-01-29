// Acres
// https://www.acmicpc.net/problem/26532

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	float a, b;
	cin >> a >> b;
	int res = ceil(a * b / 4840 / 5);
	cout << res << '\n';
}

// 5 에이커를 커버할 수 있는 옥수수씨 포대를 (a*b)제곱야드의 밭에 뿌릴 때, 가득 채우기 위해 필요한 포대 수 구하기

// a * b / 4840 / 5 - 이걸 ceil하여 정수로 출력하기