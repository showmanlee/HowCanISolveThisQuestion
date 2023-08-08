// 크림빵
// https://www.acmicpc.net/problem/28214

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n, k, p;
	cin >> n >> k >> p;
	int res = 0, cnt = 0;
	for (int i = 0; i < n * k; i++) {
		int t;
		cin >> t;
		cnt += (t == 0 ? 1 : 0);
		if (i % k == k - 1) {
			if (cnt < p) {
				res++;
			}
			cnt = 0;
		}
	}
	cout << res << '\n';
}

// k개의 크림빵 묶음이 n개 있고, 각 묶음 당 크림이 없는 크림빵이 p개 미만일 때 판매할 수 있을 때, 판매할 수 있는 크림빵 묶음 수 구하기

// 각 묶음의 크림 없는 크림빵 수를 세서 계산하기...