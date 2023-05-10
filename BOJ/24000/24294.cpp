// ГРАДИНА
// https://www.acmicpc.net/problem/24294

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int res = a + (b + 1) * 2 + c + (d + 1) * 2 + abs(c - a);
	cout << res << '\n';
}

// a*b, c*d 크기의 정원이 왼쪽 변이 일직선인 형태로 앞뒤로 붙어 있을 때, 이를 두르는 데 필요한 사각형 개수 구하기

// 형태는 ㄱ자가 됨 - 분리해보면 a + (b + 1) * 2, c + (d + 1) * 2
// 여기에 남은 공간은 abs(c - a) -> 직접 그려봅시다