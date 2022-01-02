// 수열
// https://www.acmicpc.net/problem/13274

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<long long> line(n);
	for (int i = 0; i < n; i++)
		cin >> line[i];
	sort(line.begin(), line.end());
	for (int t = 0; t < k; t++) {
		int l, r, x;
		cin >> l >> r >> x;
		vector<long long> xline, oline;
		for (int i = 0; i < n; i++) {
			if (i >= l - 1 && i < r)
				xline.push_back(line[i] + x);
			else
				oline.push_back(line[i]);
		}
		int cur = 0, xcur = 0, ocur = 0;
		while (xcur < xline.size() && ocur < oline.size())
			line[cur++] = (xline[xcur] < oline[ocur] ? xline[xcur++] : oline[ocur++]);
		if (xcur < xline.size())
			while (xcur < xline.size())
				line[cur++] = xline[xcur++];
		if (ocur < oline.size())
			while (ocur < oline.size())
				line[cur++] = oline[ocur++];
	}
	for (int i = 0; i < n; i++)
		cout << line[i] << ' ';
	cout << '\n';
}

// 어떤 수열의 일정 범위에 수를 더한 후 정렬하는 과정(쿼리)을 반복할 때 나오는 수열은?
// 쿼리 수는 1000개, 수열 길이는 100000 - nlogn 정렬을 계속 돌리기에도 부담스러움
// 쿼리를 처리할 새로운 정렬 방법이 필요함
// 어차피 수열은 정렬되어 있음 - 일정 범위에 수를 더하면, 그 일정 범위와 바깥은 각각의 정렬 상태가 유지됨
// 이를 이용해 O(n) 정렬을 할 수 있음 - 일정 범위 vs 나머지 범위 따로 딴 뒤 기수 정렬(?)
// 메모리는 충분하니 그렇게 할 수 있음