// 최솟값
// https://www.acmicpc.net/problem/10868

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int board[100001];
int mins[400001];

int init(int node, int start, int end) {
	if (start == end)
		return mins[node] = board[start];
	return mins[node] = min(init(node * 2, start, (start + end) / 2), init(node * 2 + 1, (start + end) / 2 + 1, end));
}

int res(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 1987654321;
	if (left <= start && end <= right)
		return mins[node];
	return min(res(node * 2, start, (start + end) / 2, left, right), res(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> board[i];
	init(1, 1, n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << res(1, 1, n, a, b) << '\n';
	}
}

// 길이가 n인 배열에서 주어진 범위 내 최솟값 구하기

// n이 10만이므로 n^2를 적용하면 시간초과 - 세그먼트 트리를 도입해야 함
// 각 세그먼트 트리 노드에는 현재 범위의 최솟값 저장 - 노드 범위가 1이 된 경우에는 해당 수를, 그렇지 않다면 하위 범위의 결과 중 작은 값으로 채우기
// 이후 범위를 받아서 세그먼트 트리 탐색 기반으로 최솟값 구하기
// 탐색 범위를 벗어난 경우에는 들어갈 수 없는 수(10억 이상) 반환, 탐색 범위가 목표 범위 내부인 경우 해당 노드의 값 반환, 그렇지 않다면 반으로 나눈 범위의 리턴값 중 작은 값 반환
// 세그먼트 트리의 범위 지정법을 반드시 체득할 것