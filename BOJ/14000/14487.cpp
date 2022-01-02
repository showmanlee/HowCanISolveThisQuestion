// 욱제는 효도쟁이야!!
// https://www.acmicpc.net/problem/14487

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	int res = sum;
	for (int i = 0; i < n; i++)
		res = min(res, sum - v[i]);
	cout << res << '\n';
}

// n개의 마을이 원형으로 둘러진 섬에서 양옆의 마을로 이동하는 길의 길이가 주어졌을 때, 모든 마을을 방문하는 최소 거리는?

// 모든 도로의 합을 구한 후, (합 - 도로)가 최소가 되는 값을 구하기