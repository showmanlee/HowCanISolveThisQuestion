// 사각형 면적
// https://www.acmicpc.net/problem/22341

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, c;
	cin >> n >> c;
	int a = n, b = n;
	for (int i = 0; i < c; i++) {
		int x, y;
		cin >> x >> y;
		if (x >= a || y >= b)
			continue;
		if (a * y > x * b)
			b = y;
		else
			a = x;
	}
	cout << (a * b) << '\n';
}

// n*n 격자에 점을 찍는데, 격자 안에 들어온 점 좌표에 평행하게 가로 또는 세로로 잘라 윗/왼쪽 부분이 큰 것만을 남기는 과정을 반복할 때 남는 격자의 넓이는?

// 가로로 자를 떄와 세로로 자를 때의 넓이가 같다면 가로를 우선한다
// 여기서 '자른다'라고 하는 것은 격자의 넓이를 a * y 또는 b * x로 바꾸는 것 - a,b가 원래 크기, x,y가 찍은 점 좌표
// 따라서 둘 중 더 큰 것을 찾아 해당 좌표 크기를 x 또는 y로 바꾸고, 그렇게 바꿔낸 결과의 곱을 출력하는 것