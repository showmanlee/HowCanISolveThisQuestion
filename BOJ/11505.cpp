// 구간 곱 구하기
// https://www.acmicpc.net/problem/11505

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, m, k;
long long board[1000001];
long long mults[3000001];

long long init(long long node, long long start, long long end) {
	if (start == end)
		return mults[node] = board[start];
	else
		return mults[node] = (init(node * 2, start, (start + end) / 2) * init(node * 2 + 1, (start + end) / 2 + 1, end)) % 1000000007;
}

long long res(long long node, long long start, long long end, long long left, long long right) {
	if (left > end || right < start)
		return 1;
	if (left <= start && end <= right)
		return mults[node];
	return (res(node * 2, start, (start + end) / 2, left, right) * res(node * 2 + 1, (start + end) / 2 + 1, end, left, right)) % 1000000007;
}

long long update(long long node, long long start, long long end, long long idx, long long num) {
	if (idx < start || idx > end)
		return mults[node];
	if (start == end)
		return mults[node] = num;
	return mults[node] = (update(node * 2, start, (start + end) / 2, idx, num) * update(node * 2 + 1, (start + end) / 2 + 1, end, idx, num)) % 1000000007;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k;
	for (long long i = 1; i <= n; i++)
		cin >> board[i];
	init(1, 1, n);
	for (long long i = 0; i < m + k; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) 
			update(1, 1, n, b, c);
		else
			cout << res(1, 1, n, b, c) << '\n';
	}
}

// n개의 수로 이루어진 배열에서 특정 자리의 수를 바꾸는 연산과 b~c까지의 곱(%1000000007)을 구하는 연산 처리하기

// 2042 구간 합 구하기와 사실상 같은 문제 - 다만 이번에는 곱으로 접근해야 함
// 따라서 init와 res의 경우 합을 구하던 걸 곱을 구하는 것으로 수정하면 됨 - 문제는 update
// 합의 경우 변경된 차만큼 범위값에서 증감하면 되지만, 곱의 경우 그럴 수 없음

// 따라서 update에서도 트리를 전체적으로 갱신할 필요가 있음 - 바뀐 부분이 포함된 범위에서만
// 만약 탐색 범위가 1이 되고 그 범위가 갱신된 곳이라면 트리에 해당 갱신된 값을 갱신하고 반환, 탐색 범위 내에 갱신된 값이 없다면 원래 값 반환
// 둘 다 아니라면 하위 트리 탐색하여 두 반환값의 곱 반환