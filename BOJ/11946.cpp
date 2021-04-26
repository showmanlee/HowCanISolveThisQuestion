// ACM-ICPC
// https://www.acmicpc.net/problem/11946

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<pair<int, int>, int> prr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int>> submitted(n + 1, vector<int>(m + 1));
	vector<vector<int>> times(n + 1, vector<int>(m + 1));
	vector<vector<bool>> solved(n + 1, vector<bool>(m + 1));
	for (int i = 0; i < q; i++) {
		int time, team, no;
		string submit;
		cin >> time >> team >> no >> submit;
		if (solved[team][no])
			continue;
		if (submit == "AC") {
			solved[team][no] = true;
			times[team][no] = submitted[team][no] * 20 + time;
		}
		submitted[team][no]++;
	}
	vector<prr> sorter;
	for (int i = 1; i <= n; i++) {
		prr p = { {0, 0}, i };
		for (int j = 1; j <= m; j++) {
			if (solved[i][j]) {
				p.first.first--;
				p.first.second += times[i][j];
			}
		}
		sorter.push_back(p);
	}
	sort(sorter.begin(), sorter.end());
	for (prr p : sorter)
		cout << p.second << ' ' << -p.first.first << ' ' << p.first.second << '\n';
}

// 알고리즘 대회에서 각 팀의 제출 현황이 주어졌을 때, 순위대로 정렬하기
// 순위는 해결한 문제 개수 -> 걸린 시간 수 순서대로 정렬
// 제출 기록은 경과 시간, 팀 번호, 문제 번호, 상태로 구성되어 있으며, "AC"가 아닌 경우 모두 오답 판정
// "AC"를 받으면 경과 시간 + 그 시점까지 해당 문제를 시도했던 횟수 * 20이 최종 완료 시간으로 기록된다

// 각 팀별 문제당 제출한 횟수, 경과 시간, 해결 여부를 기록하는 배열을 각각 만들어 입력을 받는다
// 만약 제출은 했으나 틀린 경우에는 제출 횟수를 늘린다
// 맞은 경우에는 해결했음을 표시하고, 해당 문제에 대한 경과 시간을 갱신한다
// 해결 이후 문제에 추가 제출이 들어오는 경우 모두 무시한다
// 입력을 마친 후 정렬용 배열을 만들어 우선순위대로 데이터를 넣는다 - 푼 문제 수는 내림차순이므로 음수, 경과 시간과 팀 번호는 오름차순이므로 양수
// 마지막으로 정렬 후 출력 순서에 맞게 출력