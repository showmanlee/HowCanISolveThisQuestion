// 동작 그만. 밑장 빼기냐?
// https://www.acmicpc.net/problem/20159

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<long long> v(n);
	long long sum = 0, sumb = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (i % 2 == 0) {
			sum += v[i];
		}
	}
	sumb = sum;
	long long res = sum;
	for (int i = n - 1; i >= 0; i -= 2) {
		sum += v[i];
		sum -= v[i - 1];
		res = max(res, sum);
	}
	sum = sumb;
	for (int i = n - 2; i >= 1; i -= 2) {
		sum -= v[i];
		sum += v[i - 1];
		res = max(res, sum);
	}

	cout << res << '\n';
}

// 숫자 카드를 위에서부터 차례대로 자신과 상대에서 분배하는 중 밑장을 한 번 뺼 수 있을 때, 얻을 수 있는 숫자 카드의 최대 합 구하기

// 순서가 나 먼저 시작되므로 기본적으로는 홀수 칸에 있는 수들의 합이 기본
// 여기서 내 순서에 밑장을 뺀다고 하면 뒤에서부터 홀수 칸의 수는 상대에게로 가고 대신 그 뒤의 짝수 칸 카드를 얻을 수 있다
// 그런데 상대에게 밑장을 빼는 게 유리한 경우도 있음 - 이 경우에는 홀수 칸 다음의 짝수 칸을 얻고 그 다음 홀수 칸을 버린다
// 구하는 과정을 n^2로 반복할 수는 없으니 홀수 칸만 누적 합을 따놓고 밑장 뺴는 타이밍에 따라 바뀌는 합을 누적시켜 계산해보자