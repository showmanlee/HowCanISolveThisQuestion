// 좌표 정렬하기 2
// https://www.acmicpc.net/problem/11651

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class cord {
public:
	int x, y;

	bool operator<(cord c) {
		if (this->y == c.y)
			return this->x < c.x;
		return this->y < c.y;
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

// 좌표 정렬하기 1에서 우선순위가 x에서 y로 바뀌었을 뿐, 나머지는 모두 동일