// 구간 합 구하기
// https://www.acmicpc.net/problem/2042

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

	cin >> n >> m >> k;
	for (long long i = 1; i <= n; i++)
		cin >> board[i];
	init(1, 1, n);
	for (long long i = 0; i < m + k; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			long long diff = c - board[b];
			board[b] = c;
			update(1, 1, n, b, diff);
		}
		else
			cout << res(1, 1, n, b, c) << '\n';
	}
}

// n개의 수로 이루어진 배열에서 특정 자리의 수를 바꾸는 연산과 b~c까지의 합을 구하는 연산 처리하기

// n이 100만이므로 일일히 바꾸고 답을 구하면 시간 초과
// 여기서 우리는 '세그먼트 트리'라는 새로운 기술을 활용할 수 있음 - 범위를 이진 트리화하여 해당 범위의 합을 구하는 이진 트리 만들기
// 이진 트리의 크기는 2^(ceil(log2(n)) + 1) - 1 - 적당히 크게 범위 주기
// 이를 위해 사용해야 하는 함수는 3개 - init, res, update

// init에서는 받은 보드의 수들을 바탕으로 트리에 수 채우기 - 현재 트리의 노드, 범위 시작점, 끝점
// 만약 시작점과 끝점이 같아지면 보드의 해당 지점 값을 채우고 반환, 그렇지 않으면 범위를 절반으로 나누고 재귀 호출하여 그 리턴값의 합을 채우고 반환

// res(sum)에서는 해당 범위의 합 구하기 - 현재 트리의 노드, 범위 시작점, 끝점, 구해야 하는 범위 좌측, 우측
// 만약 탐색 범위가 구해야 하는 범위를 벗어난 경우(left > end || right < start) 0 반환하고 탐색 종료 - [left right start end] or [start end left right]
// 만약 탐색 범위가 구해야 하는 범위 내부로 진입한 경우(left <= start && end <= right) 해당 범위의 합 반환하고 탐색 종료 - [left start end right]
// 위 두 상황이 아닌 경우 범위를 절반으로 나누고 재귀 호출하여 리턴값의 합 반환

// update에서는 바뀐 값을 토대로 해당 범위의 합 반환하기 - 현재 트리의 노드, 범위 시작점, 끝점, 바뀐 값의 인덱스, 바뀐 값의 차
// 만약 바뀐 값의 인덱스가 탐색 범위를 벗어난 경우 더 이상 탐색하지 않고 종료
// 그렇지 않다면 해당 범위의 합에 차를 적용한 후, 범위를 절반으로 나누고 재귀 호출하여 계속 갱신

// 이러한 방식으로 '범위'에 대해 이진 트리 방식을 적용하여 시간복잡도에 log2를 적용할 수 있다 - 계속 풀어보면서 체득해갑시다