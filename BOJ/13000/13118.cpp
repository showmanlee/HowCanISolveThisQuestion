// 뉴턴과 사과
// https://www.acmicpc.net/problem/13118

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> people(4);
	for (int i = 0; i < 4; i++)
		cin >> people[i];
	int x, y, r;
	cin >> x >> y >> r;
	int res = 0;
	for (int i = 0; i < 4; i++)
		if (people[i] == x)
			res = i + 1;
	cout << res << '\n';
}

// 좌표평면 상의 x축 위에 서있는 사람 4명이 있고, (x, y)에서 반지름이 r인 떨어지는 사과가 있을 때, 누가 사과에 맞는가?

// 기하학적 접근이 필요해 보이지만 사람들의 키는 고려되지 않고, 또 사과는 x축과 접하면 멈추기 때문에 단순 판정으로 접근해도 됨
// 또한 그 이유로 사과는 단 한 명만 맞는 것이 보장됨 - 그리고 떨어지는 위치는 사과의 x좌표 단 한 곳
// 따라서 사람 4명의 x축 위치와 사과의 x축 위치를 비교해 사과와 같은 x축 위치에 있는 사람이 사과를 맞게 됩니다