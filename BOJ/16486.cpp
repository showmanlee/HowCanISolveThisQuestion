// 운동장 한 바퀴
// https://www.acmicpc.net/problem/16486

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int l, d;
	cin >> l >> d;
	double res = (l * 2) + (3.141592 * 2 * d);
	cout << fixed;
	cout.precision(6);
	cout << res << '\n';
}

// 직사각형 양옆에 반원 2개가 맞닿은 형태의 운동장 트랙에서 직사각형의 가로 길이와 반원의 반지름 길이가 주어질 때, 운동장의 둘레 구하기

// 우선 직사각형 파트의 둘레는 가로 * 2 (세로는 반원이므로 볼 필요가 없음
// 그리고 반원 파트의 둘레는 2 * 반지름 * pi (원의 반지름과 같음, 여기서 pi는 3.141592)

// cout 상에서 소수점을 고정하여 출력하고 싶다면 cout << fixed; cout.precision(n);
// 이렇게 하면 소수 n자리까지 고정되어 출력되고, 자동으로 반올림도 해줌
// 해제하려면 cout.unsetf(ios::fixed); 사용하기