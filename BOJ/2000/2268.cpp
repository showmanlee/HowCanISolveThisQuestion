// 수들의 합
// https://www.acmicpc.net/problem/2268

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, m, k;
long long board[1000001];
long long sums[3000001];

long long init(long long node, long long start, long long end) {
	if (start == end)
		return sums[node] = board[start];
	else
		return sums[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
}

long long res(long long node, long long start, long long end, long long left, long long right) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return sums[node];
	return res(node * 2, start, (start + end) / 2, left, right) + res(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(long long node, long long start, long long end, long long idx, long long diff) {
	if (idx < start || idx > end)
		return;
	sums[node] += diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, idx, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (long long i = 1; i <= n; i++)
		board[i] = 0;
	init(1, 1, n);
	for (long long i = 0; i < m; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			long long diff = c - board[b];
			board[b] = c;
			update(1, 1, n, b, diff);
		}
		else {
			if (b > c)
				swap(b, c);
			cout << res(1, 1, n, b, c) << '\n';
		}
	}
}

// 처음에 모두 0으로 초기화되어 있는 크기가 n인 배열에서 선택한 범위의 합을 구하는 Sum 함수(0)과 특정 위치의 수를 바꾸는 Modify 함수(1)이 있을 때, Sum 함수 실행 결과들 출력하기

// 2042 구간 합 구하기와 기본적으로 같음 - 세그먼트 트리 기반
// 다만 이번에는 배열 초기값들이 모두 0이고, 합을 구하는 영역이 역으로 주어질 수도 있다
// 따라서 영역이 역방향으로 들어올 경우를 감안하며 처리해줘야 함
// 그것 외에는 기존 문제와 거의 동일