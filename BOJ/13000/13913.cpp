// 숨바꼭질 4
// https://www.acmicpc.net/problem/13913

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;
	vector<int> visit(100001, -1);
	vector<int> route(100001, -1);
	queue<int> q;
	q.push(n);
	visit[n] = 0;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		if (p == k)
			break;
		if (p + 1 <= 100000 && visit[p + 1] == -1) {
			visit[p + 1] = visit[p] + 1;
			route[p + 1] = p;
			q.push(p + 1);
		}
		if (p - 1 >= 0 && visit[p - 1] == -1) {
			visit[p - 1] = visit[p] + 1;
			route[p - 1] = p;
			q.push(p - 1);
		}
		if (p * 2 <= 100000 && visit[p * 2] == -1) {
			visit[p * 2] = visit[p] + 1;
			route[p * 2] = p;
			q.push(p * 2);
		}
	}
	cout << visit[k] << '\n';
	int i = k;
	vector<int> res;
	while (i != -1) {
		res.push_back(i);
		i = route[i];
	}
	for (int i = res.size() - 1; i >= 0; i--)
		cout << res[i] << ' ';
	cout << '\n';
}

// 0~100000까지의 선분 상에 나는 n에 있고, 목표가 k에 있다. 목표로 이동하기 위해 +1, -1, *2로 이동할 수 있는데, 이 때 잡을 수 있는 최소 시간과 그 경로의 수는?
// 1697 숨바꼭질과 달리 궤적을 출력해야 함
// 큐 안에 vector를 넣을 수는 없으니, 이 칸이 어디에서 들어왔는지를 체크하는 배열을 만든다 - visit는 한 번만 들어오는 게 보장됨
// 이후 탈출하면 끝 지점부터 처음으로 돌아가면서 배열에 담은 후, 이를 역순으로 출력하면 정순 경로가 출력된다(아무거나 출력해도 됨)