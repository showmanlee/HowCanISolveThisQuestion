// 무알콜 칵테일
// https://www.acmicpc.net/problem/2896

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cout << fixed;
    cout.precision(6);

	float a, b, c, i, j, k;
	cin >> a >> b >> c >> i >> j >> k;
	float p = min(a / i, min(b / j, c / k));
	cout << (a - i * p) << ' ' << (b - j * p) << ' ' << (c - k * p) << '\n';
}

// 주스 세 종류의 양과 칵테일 한 잔을 만들기 위해 필요한 주스의 양이 주어질 때, 주어진 주스로 최대한 칵테일을 만든 후 남는 주스의 양 출력하기

// 칵테일을 꼭 한 잔 단위로 만들 필요가 없음 - 정수가 아닌 실수 문제라는 것
// 여기서 최대로 만들 수 있는 칵테일의 양은 (현재 주스 / 필요한 주스)의 최솟값
// 이 값을 구한 뒤, 주스들을 써봅시다s