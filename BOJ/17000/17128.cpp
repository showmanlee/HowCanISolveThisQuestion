// 소가 정보섬에 올라온 이유
// https://www.acmicpc.net/problem/17128

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	vector<long long> board(n), muls(n, 1);
	long long res = 0;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++)
			muls[i] *= board[(i + j) % n];
		res += muls[i];
	}
	for (int t = 0; t < q; t++) {
		int p;
		cin >> p;
		p--;
		for (int i = 0; i < 4; i++) {
			muls[(p + n - i) % n] *= -1;
			res += muls[(p + n - i) % n] * 2;
		}
		cout << res << '\n';
	}
}

// 원형으로 둘러 앉은 숫자가 적힌 소들이 있고, 연속한 네 마리 소들의 품질 점수를 곱한 값들을 모두 곱한 값을 구하려고 한다.
// 그런데 누가 어떤 소에 적힌 수를 *-1하려고 할 때, 변경된 값은?

// 소와 장난은 각각 20만 회 - 바꿀 때마다 새로 값을 구하기는 어려움
// 그런데 장난은 그냥 적힌 수 하나에 -1을 곱하는 것 뿐 - 네 마리 소의 곱도 음수로 바뀌기만 하지 절댓값이 바뀌지는 않는다
// i~i+3번째 소의 값을 모두 곱한 결과가 muls[i]일 경우, i번째 소에 장난을 치면 muls[i-3 ~ i]의 값에 -1을 곱해주면 된다
// 결과값에 변경된 값을 적용하려면 -1을 곱해준 값 * 2를 결과값에 더해주면 됨