// 정육각형과 삼각형
// https://www.acmicpc.net/problem/14264

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	double n;
	cin >> n;
	cout << fixed;
	cout.precision(10);
	double p = n * n * sqrt(3) / 2 / 2;
	cout << p << '\n';
}

// 정육각형에 대각선 3개를 그려 삼각형 4개를 만들 때, 그 중 가장 작은 삼각형 넓이의 최댓값은?

// 1, 3, 5번째 꼭짓점을 정삼각형 형태로 이은 형태에서 외곽에 있는 이등변삼각형의 넓이를 구하라는 말
// 해당 이등변삼각형의 넓이는 한 변의 양끝점에서 정육각형 중심으로 선분을 이어 만든 정삼각형의 넓이와 같음
// 그리고 그 정삼각형의 넓이는 n * (n * cos(60)) / 2 = n * (n * 2 / sqrt(3)) / 2