// 도서실 거리두기
// https://www.acmicpc.net/problem/20665

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, t, p;
	cin >> n >> t >> p;
	vector<pr> person(t);
	for (int i = 0; i < t; i++)
		cin >> person[i].first >> person[i].second;
	sort(person.begin(), person.end());
	vector<int> seat(n + 1, -1);
	int res = 0, cnt = 0;
	int idx = 0, capacity = 0;
	for (int h = 9; h < 21; h++) {
		for (int m = 0; m < 60; m++) {
			for (int i = 1; i <= n; i++) {
				if (seat[i] != -1 && person[seat[i]].second == h * 100 + m) {
					seat[i] = -1;
					capacity--;
				}
			}
			while (idx < t && person[idx].first == h * 100 + m) {
				int pos = 0;
				if (capacity == 0) 
					pos = 1;
				else {
					vector<int> finder(n + 1, -1);
					queue<int> q;
					for (int i = 1; i <= n; i++) {
						if (seat[i] != -1) {
							q.push(i);
							finder[i] = 0;
						}
					}
					while (!q.empty()) {
						int p = q.front();
						q.pop();
						if (p - 1 > 0 && finder[p - 1] == -1) {
							finder[p - 1] = finder[p] + 1;
							q.push(p - 1);
						}
						if (p + 1 <= n && finder[p + 1] == -1) {
							finder[p + 1] = finder[p] + 1;
							q.push(p + 1);
						}
					}
					int far = 0;
					for (int i = 1; i <= n; i++) {
						if (finder[i] > far) {
							far = finder[i];
							pos = i;
						}
					}
				}
				seat[pos] = idx;
				capacity++;
				if (person[idx].first == person[idx].second) {
					seat[pos] = -1;
					capacity--;
				}
				idx++;
			}
			if (seat[p] == -1)
				cnt++;
			else if (cnt != 0) {
				res += cnt;
				cnt = 0;
			}
		}
	}
	res += cnt;
	cout << res << '\n';
}

// 9시부터 21시까지 예약제로 운영되는 도서실에서 이용자가 다음과 같은 과정으로 좌석을 선택할 때, 관리자가 원하는 자리를 이용할 수 있는 총 시간은?
// - 독서실 전체가 비어 있다면 1번 좌석, 그렇지 않다면 앉은 좌석(들)에서 가장 멀리 떨어진 좌석 중 좌석 번호가 가장 작은 번호에 앉느다
// - 예약 시작 시간이 같다면 이용 시간이 짧은 사람이 우선으로 앉는다

// 9시부터 21시까지 계속해서 시뮬레이션을 돌려봐야 함 - 마침 시간도 4자리 정수로 주어지니, 시침과 분침을 2차원 for로 만들어 접근해보자
// 이용자의 시간은 4자리 정수 pair로 받은 다음, 이를 정렬하여 입장 순서를 만들고, 시각을 돌린다
// 매 시각마다 빠지는 사람(들)이 있다면 해당 자리에서 빼주고, 현재 인원수에서 하나 빼준다
// 그리고 현재 들어온 사람(들)이 있다면 원하는 자리에 넣어준다
// - 만약 도서실이 빈 상태라면 무조건 1번 자리에 넣어준다
// - 그렇지 않다면 bfs를 이용해 각 자리에 대한 거리 배열을 만들어준 후, 이를 보고 조건의 맞는 자리를 찾아 넣어준다
// 이렇게 자리 이동은 마친 뒤 원하는 자리가 빈 상태라면 가용 시간을 계속 누적하고, 그렇지 않다면 누적된 가용 시간을 결과값에 넣어주고 가용 시간을 비운다

// 문제에서 언급되지 않았지만 유의해야 될 점들이 여러 가지 있음
// - 퇴장이 입장보다 우선됨(예제 2) - 퇴장 판정을 우선하고 입장 판정을 해야 함
// - 입장과 퇴장이 동시에 이뤄질 수 있음 - 이 경우 입장 과정과 동시에 퇴장 과정이 진행되어야 한다 - 관리자가 원하는 위치는 해당 시각에 여전히 남기에 가용 시간 누적은 유지한다