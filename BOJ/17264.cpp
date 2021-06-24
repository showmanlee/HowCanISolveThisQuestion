// I AM IRONMAN
// https://www.acmicpc.net/problem/17264

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, p, w, l, g;
	cin >> n >> p >> w >> l >> g;
	map<string, string> result;
	for (int i = 0; i < p; i++) {
		string a, b;
		cin >> a >> b;
		result[a] = b;
	}
	int pts = 0;
	bool res = false;
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		if (result.count(t) == 0)
			pts -= l;
		else 
			pts += (result[t] == "W" ? w : -l);
		if (pts < 0)
			pts = 0;
		if (pts >= g)
			res = true;
	}
	cout << (res ? "I AM NOT IRONMAN!!" : "I AM IRONMAN!!") << '\n';
}

// 다른 사람과 팀을 이뤄서 하는 게임에서 특정 플레이어와 플레이하면 이기거나 지는 것을 알고, 아이언 티어를 벗어나기 위해 g점이 필요할 때, 주어진 사람들과 순서대로 팀을 맺어 게임하면서 g점에 도달하는 순간이 있는가?

// 리스트에 주어지지 않은 팀원이 등장할 수도 있지만, 이들과 만나면 모두 진다고 간주 - 또한 점수는 0점 아래로 내려가지 않고, g점을 넘은 순간이 있다면 그 이후 점수가 떨어져도 성공했다고 판정
// 플레이어 리스트는 map으로 관리 - 이 사람은 W 또는 L을 가지고 있다
// 이후 팀원 입력을 받으며 count를 통해 map에 등재되지 않은 사람임이 확인되면 점수를 l만큼 빼고, 등재되어 있다면 등재된 대로 w점을 추가하거나 l점을 뺀다
// 이후 점수가 0점 미만으로 떨어지면 0점으로 올리고, g점 이상이 됐다면 결과값에 성공으로 기록한다