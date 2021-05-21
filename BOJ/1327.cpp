// 소트 게임
// https://www.acmicpc.net/problem/1327

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	string target, start;
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		start += to_string(p);
		target += to_string(i);
	}
	queue<string> q;
	map<string, int> visit;
	visit[start] = 1;
	int res = -1;
	q.push(start);
	while (!q.empty()) {
		string s = q.front();
		q.pop();
		if (s == target) {
			res = visit[s] - 1;
			break;
		}
		for (int i = 0; i <= n - k; i++) {
			string p = s;
			for (int j = 0; j < k / 2; j++) {
				swap(p[i + j], p[i + k - j - 1]);
			}
			if (visit[p] == 0) {
				visit[p] = visit[s] + 1;
				q.push(p);
			}
		}
	}
	cout << res << '\n';
}

// 1부터 n까지의 수로 구성된 순열에서 연속된 k개의 수의 순서를 뒤집는 과정을 반복해 오름차순으로 만들 수 있는가? 있다면 얼마나 걸리는가?

// n은 최대 8까지이므로 순열은 문자열로 나타낼 수 있음 - 그리고 연속된 k개의 수를 뒤집는 과정은 그 가짓수가 한정되어 있음(n - k + 1가지)
// 거기에 최소 횟수를 구하는 문제 - 문자열 기반 bfs로 풀어볼 수 있음
// 여기서 visit 배열은 string을 인덱스로 하는 map으로 구현 - 0이 기본값이기에 1부터 과정 수를 기록, 마지막 출력 단에서는 1 빼기
// 주어진 순열를 문자열로 변환하면서 목표로 하는 순열도 함께 생성 - 1부터 n까지 차례대로 적힌 문자열
// 이후 큐를 준비한 후 돌리면서 뒤집은 경우의 수를 방문하지 않았다면(visit == 0) 방문하며 넣어주고, 목적지에 도달하면 탈출 후 출력하기