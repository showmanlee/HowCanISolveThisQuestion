// 붙임성 좋은 총총이
// https://www.acmicpc.net/problem/26069

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	map<string, bool> dance;
	int res = 0;
	dance["ChongChong"] = false;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		if (!dance["ChongChong"] && (a == "ChongChong" || b == "ChongChong")) {
			dance["ChongChong"] = true;
			res++;
		}
		if (dance[a] ^ dance[b]) {
			dance[a] = dance[b] = true;
			res++;
		}
	}
	cout << res << '\n';	
}

// 두 사람이 만난 기록이 순서대로 주어진 상황에서 "ChongChong"이 추는 무지개 댄스가 만난 사람에게 전염된다고 할 때, 기록이 끝나는 시점에서 무지개 댄스를 추고 있는 사람은?

// bfs 같아 보이지만 bfs가 아님 - 동시에 만나는 게 아닌 순서대로 만나기 떄문
// 무지개 댄스 전염 여부를 map으로 두고, 기록을 받으며 ChongChong이 처음으로 등장했다면 총총 전염 여부를 true로 둔다 - 그리고 감염자 수를 1로 둔다
// 이후 전염된 사람과 안 된 사람이 만난 경우 전염시키고 감염자 수를 늘린다 - 기록 모두 받은 뒤 결과 출력하기