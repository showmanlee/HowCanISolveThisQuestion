// 랭킹전 대기열
// https://www.acmicpc.net/problem/20006

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, string> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<pr>> room;
	for (int i = 0; i < n; i++) {
		int a;
		string b;
		cin >> a >> b;
		pr p = { a, b };
		bool inserted = false;
		for (vector<pr>& v : room) {
			if (v.size() == m)
				continue;
			if (a <= v[0].first + 10 && a >= v[0].first - 10) {
				v.push_back(p);
				inserted = true;
				break;
			}
		}
		if (!inserted) {
			room.push_back(vector<pr>());
			room[room.size() - 1].push_back(p);
		}
	}
	for (vector<pr>& v : room) {
		cout << (v.size() == m ? "Started!" : "Waiting!") << '\n';
		sort(v.begin(), v.end(), [](pr a, pr b) { return a.second < b.second; });
		for (pr p : v)
			cout << p.first << ' ' << p.second << '\n';
	}
}

// 레벨이 다른 플레이어들이 순서대로 들어오는 상황에서 첫 번째 플레이어를 기준으로 레벨이 +-10인 플레이어 m명을 묶어 한 팀을 만들 때, 만들어진 팀과 그 목록 출력하기

// 2차원 vector room을 만들어서 하나씩 넣어간다
// 플레이어 정보를 입력받은 후, 생성된 방을 보며 채워지지 않은 방인데 현재 플레이어 레벨이 해당 방의 첫 번째 플레이어 점수 범위에 있는 경우 해당 방에 삽입
// 만약 어떤 방에도 삽입되지 못했다면 새로운 방을 만들어 그곳에 삽입
// 이후 방들을 출력하는데, 방이 채워졌다면 Started!, 그렇지 않으면 Waiting! 출력
// 그리고 방 안의 플레이어들을 닉네임 사전 순으로 정렬한 후 출력하기