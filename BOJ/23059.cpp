// 리그 오브 레게노
// https://www.acmicpc.net/problem/23059

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, string> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	map<string, vector<string>> route;
	map<string, int> dim;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		route[a].push_back(b);
		dim[b]++;
		if (dim.count(a) == 0)
			dim[a] = 0;
	}
	priority_queue<pr, vector<pr>, greater<pr>> pq;
	for (auto p : dim) {
		if (p.second == 0)
			pq.push({ p.second, p.first });
	}
	vector<string> res;
	while (!pq.empty()) {
		int level = pq.top().first;
		string cur = pq.top().second;
		pq.pop();
		res.push_back(cur);
		for (string s : route[cur]) {
			dim[s]--;
			if (dim[s] == 0)
				pq.push({ level + 1, s });
		}
	}
	if (res.size() != dim.size())
		cout << -1 << '\n';
	else {
		for (string s : res)
			cout << s << '\n';
	}
}

// 어떤 아이템을 구매하기 위해 필요한 선행 아이템 관계들이 주어졌을 때, 주어진 아이템을 모두 구매하기 위해 필요한 순서 출력하기

// 위상 정렬을 이용한 전체 순서 구하기 - 그런데 이번에는 각 개체가 문자열로 주어진다
// 따라서 일반 배열이 아닌 map 형태로 관리를 해줘야 함 - 그리고 동일 수준은 사전 순서대로 정렬해야 함
// 동일 수준 정렬을 위해 위상 탐색용 큐는 pq로 관리
// 이후 탐색 결과의 수가 입력된 단어 수보다 적다면 모든 아이템을 살 수 없다는 의미이므로 -1 출력, 그렇지 않다면 순서대로 출력하기

// 전체 순서 구하기용 위상 정렬 하시는 법은 아시죠? - 위의 방법대로 하시면 됩니다