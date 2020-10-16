// 좌표 정리
// https://www.acmicpc.net/problem/11650

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class cord {
public:
	int x, y;

	bool operator<(cord c) {
		if (this->x == c.x)
			return this->y < c.y;
		return this->x < c.x;
	}
};

int main(void) {
	int n;
	cin >> n;
	vector<cord> c(n);
	for (int i = 0; i < n; i++)
		cin >> c[i].x >> c[i].y;
	sort(c.begin(), c.end());
	for (int i = 0; i < n; i++)
		cout << c[i].x << ' ' << c[i].y << '\n';
}

// 클래스 안에 operator< 구현 시 별도의 소팅 함수를 만들 필요 없음