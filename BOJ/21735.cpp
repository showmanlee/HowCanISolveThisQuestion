// 눈덩이 굴리기
// https://www.acmicpc.net/problem/21735

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<int, pr> prr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> snows(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> snows[i];
	int res = 0;
	queue<prr> q;
	q.push({ 0, {1, 0} });
	while (!q.empty()) {
		int pos = q.front().first;
		int size = q.front().second.first;
		int time = q.front().second.second;
		q.pop();
		if (time >= m || pos >= n) {
			res = max(res, size);
			continue;
		}
		if (pos + 1 > n)
			res = max(res, size);
		else {
			int nsize = size + snows[pos + 1];
			q.push({ pos + 1, {nsize, time + 1} });
		}
		if (pos + 2 > n)
			res = max(res, size);
		else {
			int nsize = size / 2 + snows[pos + 2];
			q.push({ pos + 2, {nsize, time + 1} });
		}
	}
	cout << res << '\n';
}

// 처음에 크기가 1인 눈덩이을 다음 1칸으로 굴릴 때는 해당 위치의 눈이 눈덩이에 추가되고, 다음 2칸으로 던질 때는 눈덩이가 반으로 쪼개진 뒤 해당 위치의 눈이 쪼개진 눈덩이에 추가될 때, m초 안에 얻을 수 있는 눈덩이의 최대 크기는?

// bfs 스타일로 접근
// 첫 위치에서 한 칸 이동 시, 두 칸 이동 시 눈덩이 크기 차이를 기록해 큐에 삽입 - 만약 보드를 벗어나는 경우 실행하지 않음
// 만약 보드를 벗어났거나 벗어날 예정이거나 시간이 초과된 경우 지금까지의 눈덩이 크기 이용해 결과값을 갱신 - bfs 종료 이후 출력