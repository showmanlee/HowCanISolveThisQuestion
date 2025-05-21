// 헤키레키잇센
// https://www.acmicpc.net/problem/33897

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int prev = -1, len = 0;
	int resa = 1, resb = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (prev <= p) {
			len++;
			resb = max(resb, len);
		} else {
			resa++;
			len = 1;
		}
		prev = p;
	}
	cout << resa << ' ' << resb << '\n';
}

// 주어진 수열을 나눠서 얻을 수 있는 비내림차순 부분수열의 최소 개수와 부분수열의 최대 길이 출력하기