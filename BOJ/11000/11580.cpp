// Footprint
// https://www.acmicpc.net/problem/11580

#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;
	pr pos = { 0, 0 };
	set<pr> res;
	res.insert(pos);
	for (char c : s) {
		if (c == 'E')
			pos.first++;
		if (c == 'W')
			pos.first--;
		if (c == 'S')
			pos.second--;
		if (c == 'N')
			pos.second++;
		res.insert(pos);
	}
	cout << res.size() << '\n';
}

// 2차원 좌표공간에서 원점에서 출발해 이동한 경로가 주어질 때, 밟은 좌표의 수는?

// 나온 좌표 확인에 중복 없는 자료구조인 set을 활용
// 이동 방향에 따라 현재 위치를 변화시킨 후 해당 좌표를 set에 넣는다
// 이후 set에 있는 좌표의 수가 답