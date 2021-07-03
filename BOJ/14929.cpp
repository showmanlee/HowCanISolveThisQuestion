// 귀찮아 (SIB)
// https://www.acmicpc.net/problem/14929

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<int> board(n + 1), sums(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> board[i];
		sums[i] = sums[i - 1] + board[i];
	}
	long long res = 0;
	for (int i = 1; i <= n; i++)
		res += (sums[n] - sums[i]) * board[i];
	cout << res << '\n';
}

// 주어진 수열 x의 서로 다른 두 인덱스를 a, b라고 할 때, a < b를 만족하는 모든 x[a] * x[b]의 합 구하기

// 일단 n이 10만 - n^2식 접근으로는 불가능
// n으로 접근할 수 있는 방법? - a < b일 때 답에 a * (a + 1 ~ b)가 있으므로 누적합 원리 활용하기
// 먼저 수열을 받으면서 해당 시점까지의 원소 누적합도 같이 구해 배열에 넣는다
// 이후 수열을 순회하며 (전체 합 - 해당 지점까지의 합) * 현재 수를 계속 더한다