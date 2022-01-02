// 친구비
// https://www.acmicpc.net/problem/16562

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[10001];
int money[10001];

int finding(int p) {
	if (p == parent[p])
		return p;
	parent[p] = finding(parent[p]);
	return parent[p];
}

void unioning(int a, int b) {
	int pa = finding(a);
	int pb = finding(b);
	if (pa > pb)
		parent[pa] = pb;
	else if (pb > pa)
		parent[pb] = pa;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		cin >> money[i];
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		unioning(a, b);
	}
	for (int i = 1; i <= n; i++)
		finding(i);
	vector<int> fees(n + 1, 987654321);
	for (int i = 1; i <= n; i++)
		fees[parent[i]] = min(fees[parent[i]], money[i]);
	sort(fees.begin(), fees.end());
	int res = 0;
	for (int i : fees) {
		if (i == 987654321)
			break;
		res += i;
	}
	if (res > k)
		cout << "Oh no\n";
	else
		cout << res << '\n';
}

// 1명의 친구비를 내면 그 사람과 친구인 사람들도 모두 친구로 만들 수 있을 때, 수중에 있는 돈으로 모든 친구를 사귈 수 있는가?

// 친구의 친구 = 친구 그룹 - union-find로 각 친구 그룹에 번호를 부여하자
// 새로운 친구 관계가 주어지면 union으로 묶어주기 - 하지만 union만으로는 parent 내의 번호가 그룹 대표 번호가 됨을 보장할 수 없음
// 따라서 친구 관계 입력을 마친 후 모든 사람에 대해 find를 한번씩 돌려줌으로서 parent 내의 번호를 그룹 대표 번호로 모두 갱신시켜주기
// 이렇게 하면 하나의 그룹에 하나의 고유 번호가 생기는 효과를 얻을 수 있

// 이후 한 그룹의 최소 친구비를 기록하는 fees 배열을 만든 후 모든 사람의 친구비를 순회하며 해당 그룹의 최소 친구비로 갱신
// fees는 최초에 아주 큰 값으로 초기화해주기 - 정확히 몇 개의 그룹이 있는지 알 수 없기에 사람 수만큼 크기 지정
// 이후 해당 배열을 정렬한 후 아주 큰 값이 나오기 전까지 그룹 별 최소 친구비를 결과값에 누적
// 만약 결과값이 수중의 돈보다 많은 경우 Oh no 출력