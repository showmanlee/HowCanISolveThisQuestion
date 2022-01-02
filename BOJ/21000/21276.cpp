// 계보 복원가 호석
// https://www.acmicpc.net/problem/21276

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<string> roster(n);
	for (int i = 0; i < n; i++)
		cin >> roster[i];
	int m;
	cin >> m;
	map<string, int> dim;
	map<string, vector<string>> board;
	for (int i = 0; i < m; i++) {
		string a, b;
		cin >> a >> b;
		dim[a]++;
		board[b].push_back(a);
	}
	vector<string> ancestors;
	map<string, vector<string>> family;
	queue<string> q;
	for (int i = 0; i < n; i++) {
		if (dim[roster[i]] == 0) {
			ancestors.push_back(roster[i]);
			q.push(roster[i]);
		}
	}
	while (!q.empty()) {
		string p = q.front();
		q.pop();
		for (string s : board[p]) {
			dim[s]--;
			if (dim[s] == 0) {
				family[p].push_back(s);
				q.push(s);
			}
		}
	}
	
	cout << ancestors.size() << '\n';
	sort(ancestors.begin(), ancestors.end());
	for (string s : ancestors)
		cout << s << ' ';
	cout << '\n';
	sort(roster.begin(), roster.end());
	for (string s : roster) {
		cout << s << ' ' << family[s].size() << ' ';
		if (!family[s].empty()) {
			sort(family[s].begin(), family[s].end());
			for (string ss : family[s])
				cout << ss << ' ';
		}
		cout << '\n';
	}
}

// 마을에 살고 있는 사람들과 그 사람들의 자손 - 조상 관계가 주어질 때, 최상위 조상의 수와 목록, 그리고 각각의 직계 자손의 수와 목록 출력하기
// 즉, 자손 - 조상(직계가 아닐 수 있음) 관계만으로 완전한 가계도 만들기 - 최상위 조상이 여러 명일 수도 있음

// 위상 정렬을 이용해 풀 수 있는 문제 - 인덱스를 string으로 받기 위해 map을 적극적으로 활용하기
// 우선 사람들을 받고, 자손 - 조상 관계를 받는다
// 관계를 받는 과정에서 위상 정렬을 위해 해당 인물이 몇 명 아래에 있는지 표시하는 dim과 해당 인물의 자식들을 저장하는 board에도 정보 넣어주기
// 이후 dim == 0인 사람들은 최상위 조상이므로 최상위 조상 목록에 넣어주고, 위상 정렬을 위한 큐에도 삽입하여 위상 정렬 진행
// 위상 정렬 과정에서 dim == 0이 될 경우 그 사람이 직계 자손임을 의미 - 직계 자손을 담는 family에 해당 자손 저장
// 마지막으로 문제에 나온 대로 시조, 개인별 자손 현황 출력하기
// 모든 배열은 출력 전 정렬이 필요함에 주의