// 연속구간
// https://www.acmicpc.net/problem/2495

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int t = 0; t < 3; t++) {
		int n;
		cin >> n;
		int res = 1, combo = 1, prev = n % 10;
		n /= 10;
		while (n != 0) {
			if (n % 10 == prev)
				combo++;
			else
				combo = 1;
			res = max(res, combo);
			prev = n % 10;
			n /= 10;
		}
		cout << res << '\n';
	}
}

// 3개의 8자리 수에 대해 같은 숫자가 연속으로 등장하는 최대 길이 출력하기

// 이전 자리 수를 기록하고, 현재 자리 수가 같으면 콤보 올리고, 그렇지 않으면 1로 초기화
// 그렇게 콤보가 갱신될 때마다 결과값보다 높은 콤보가 나오면 해당 값을 결과값으로 갱신