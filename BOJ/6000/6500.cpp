// 랜덤 숫자 만들기
// https://www.acmicpc.net/problem/6500

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		vector<bool> v(10000);
		int res = 1;
		v[n] = true;
		while (true) {
			int p = n * n;
			p = p / 100 % 10000;
			if (v[p]) {
				break;
			}
			v[p] = true;
			res++;
			n = p;
		}
		cout << res << '\n';
	}
}

// 주어진 최대 4자리 정수를 제곱한 후 가운데 4자리만 가져와서 만들 수 있는 정수의 개수는?

// 직접 계산해보면 됩니다 - 마킹은 배열로
// 같은 수가 들어가면 결과도 같으니, 이미 만들어진 수로 돌아오면 탐색 종료