// 수빈이와 수열
// https://www.acmicpc.net/problem/10539

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> board(n), res(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		res[i] = board[i] * (i + 1) - sum;
		sum += res[i];
	}
	for (int i = 0; i < n; i++)
		cout << res[i] << ' ';
	cout << '\n';
}

// 어떤 수열의 값들을 해당 항까지의 평균값으로 바꾼 결과가 주어졌을 때, 원래 수열 출력하기

// 우선 첫 값은 주어진 값과 동일함 - 하나의 평균은 /1이니까
// 그 다음부터는 주어진 값에서 i를 곱한 후 직전까지의 원래 수열 값의 합을 뺀 것 - 지금은 평균값이 소수로 나오거나 절사되었다는 언급이 없음
// 이러한 규칙대로 원래 수열을 복구한 뒤 출력하기