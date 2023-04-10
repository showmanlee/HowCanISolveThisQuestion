// 인기 투표
// https://www.acmicpc.net/problem/11637

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		vector<pr> v(n);
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			int p;
			cin >> p;
			sum += p;
			v.push_back({p, i});
		}
		sort(v.begin(), v.end(), greater<pr>());
		if (v[0].first == v[1].first) {
			cout << "no winner\n";
		} else {
			cout << (v[0].first > sum / 2 ? "majority" : "minority") << " winner " << v[0].second << '\n';
		}
	}
}

// 다수결 투표의 득표수가 주어졌을 때, 당선자가 1명일 경우 번호와 과반 득표 여부를, 아닐 경우 아니라고 출력하기

// 득표수와 id를 pair로 묶어서 받고 정렬하기 - 받은 득표수를 누적해서 총 득표수 구하기
// 이렇게 해서 최다 득표수가 2명 이상이라면 당선자 없다고 쓰고, 아니면 비교해서 출력하기