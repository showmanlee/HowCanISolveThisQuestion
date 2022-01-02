// 물통
// https://www.acmicpc.net/problem/2251

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> litter(3);
	cin >> litter[0] >> litter[1] >> litter[2];
	vector<int> beg = { 0, 0, litter[2] };
	vector<bool> res(litter[2] + 1);
	vector<vector<vector<bool>>> visit(litter[0] + 1, vector<vector<bool>>(litter[1] + 1, vector<bool>(litter[2] + 1)));
	queue<vector<int>> q;
	q.push(beg);
	visit[beg[0]][beg[1]][0] = true;
	while (!q.empty()) {
		vector<int> p = q.front();
		q.pop();
		if (p[0] == 0)
			res[p[2]] = true;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j)
					continue;
				vector<int> pp = p;
				while (pp[i] != 0 && pp[j] != litter[j]) {
					pp[i]--;
					pp[j]++;
				}
				if (!visit[pp[0]][pp[1]][pp[2]]) {
					visit[pp[0]][pp[1]][pp[2]] = true;
					q.push(pp);
				}
			}
		}
	}
	for (int i = 0; i <= litter[2]; i++)
		if (res[i])
			cout << i << ' ';
	cout << '\n';
}

// 넣을 수 있는 물의 양이 다른 물통 3개가 있고, 처음 상태는 마지막 물통만 물이 가득 차있는 상태
// 여기서 어떤 물통의 물을 내 물통이 비거나 다른 물통이 가득 찰 때까지 붓는 과정을 반복할 때, 첫 번째 물통이 빈 상태에서 마지막 물통에 존재할 수 있는 물의 양들 출력하기

// 케이스를 하나씩 찾기 위해 bfs를 사용해볼 수 있음
// visit 배열은 3차원으로 두고, 큐에는 물통 3개를 모두 넣어 처리하기 - 물통 3개를 2차원 for로 순회하며, 한 물통이 비거나 찰 때까지 부은 후, 해당 상태가 visit에 기록되지 않으면 큐에 삽입
// 그리고 그 전에 큐에서 빠져나온 경우가 첫 번째 물통이 빈 상태인 경우, 마지막 물통의 상태를 결과 배열에 체크해주기
// 이후 마지막 물통의 상태가 등장했는지 여부를 표시했던 결과 배열을 순회하며 등장한 경우 출력하기

// 이번 코드를 짜며 알 수 있는 것 - vector 역시 {}로 초기화할 수 있다, queue 등 stl 컨테이너에 vector를 인수로 넣을 수 있다
// 앞으로 순회용으로 써먹으려 할 때 써먹어보자