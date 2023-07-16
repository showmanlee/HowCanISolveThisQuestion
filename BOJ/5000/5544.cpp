// 리그
// https://www.acmicpc.net/problem/5544

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> points(n + 1);
	for (int i = 0; i < n * (n - 1) / 2; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (c > d) {
			points[a] += 3;
		} else if (c < d) {
			points[b] += 3;
		} else {
			points[a]++;
			points[b]++;
		}
	}
	vector<pr> sorter(n);
	vector<int> res(n + 1);
	for (int i = 1; i <= n; i++) {
		sorter[i - 1] = {points[i], i};
	}
	sort(sorter.begin(), sorter.end(), greater<pr>());
	for (int i = 1; i <= n; i++) {
		res[sorter[i - 1].second] = i;
		if (i > 1 && sorter[i - 1].first == sorter[i - 2].first) {
			res[sorter[i - 1].second] = res[sorter[i - 2].second];
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << res[i] << '\n';
	}
}

// n팀이 참가하는 승무패 3/1/0점 방식의 풀리그 결과가 주어질 때, 각 팀의 승점에 따른 순위 출력하기

// 계산 -> 정렬 -> 출력
// 동타일 경우 순위도 같음에 유의해야 함