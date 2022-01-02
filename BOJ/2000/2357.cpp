// 최솟값과 최댓값
// https://www.acmicpc.net/problem/2357

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int board[100001];
int mins[400001];
int maxs[400001];

int init_min(int node, int start, int end) {
	if (start == end)
		return mins[node] = board[start];
	return mins[node] = min(init_min(node * 2, start, (start + end) / 2), init_min(node * 2 + 1, (start + end) / 2 + 1, end));
}

int init_max(int node, int start, int end) {
	if (start == end)
		return maxs[node] = board[start];
	return maxs[node] = max(init_max(node * 2, start, (start + end) / 2), init_max(node * 2 + 1, (start + end) / 2 + 1, end));
}

int res_min(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 1987654321;
	if (left <= start && end <= right)
		return mins[node];
	return min(res_min(node * 2, start, (start + end) / 2, left, right), res_min(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int res_max(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return maxs[node];
	return max(res_max(node * 2, start, (start + end) / 2, left, right), res_max(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> board[i];
	init_min(1, 1, n);
	init_max(1, 1, n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << res_min(1, 1, n, a, b) << ' ' << res_max(1, 1, n, a, b) << '\n';
	}
}

// 길이가 n인 배열에서 주어진 범위 내 최솟값과 최댓값 구하기

// n이 10만이므로 n^2를 적용하면 시간초과 - 세그먼트 트리를 도입해야 함
// 그리고 최솟값과 최댓값이 범위 별로 대응되지 않을 수도 있기 때문에 세그먼트 트리도 2개를 운영해야 함
// 따라서 각 트리에 맞춰 해당 범위의 최솟값/최댓값이 들어갈 수 있도록 초기 설정해준 뒤, 주어지는 범위에 맞춰 최솟값과 최댓값 출력하기
// 10868 최솟값의 확장 - 문제 나온 순서로 보면 10868이 이 문제의 축소판이지만

// solved.ac 랭킹 세자릿수 진입! - 새로운 알고리즘과 함께 세자릿수 랭크를 유지해봅시다