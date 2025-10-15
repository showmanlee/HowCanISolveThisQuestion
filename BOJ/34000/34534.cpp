// Form a Straight!
// https://www.acmicpc.net/problem/34534

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> v(5);
	for (int i = 0; i < 5; i++) {
		cin >> v[i];
	}
	int res = 987654321;
	for (int i = 1; i <= 5; i++) {
		int r = 5;
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (v[k] == j + i) {
					r--;
					break;	
				}
			}
		}
		res = min(res, r);
	}
	cout << res << '\n';
}

// 1~9까지 중 5개를 뽑았을 때, 뽑은 숫자를 바꾸어 스트레이트로 만드는데 바꿔야 하는 숫자 개수 구하기