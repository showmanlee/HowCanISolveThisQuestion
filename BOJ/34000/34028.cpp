// 우리의 다정한 계절 속에(Seasons of Memories)
// https://www.acmicpc.net/problem/34028

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int y, m, d;
	cin >> y >> m >> d;
	m++;
	if (m > 12) {
		m = 1;
		y++;
	}
	m--;
	int res = (y - 2015) * 4 + (m / 3 + 1);
	cout << res << '\n';
}

// 2015년 1월 16일부터 주어진 날짜까지 몇 개의 계절을 함께했는지 구하기