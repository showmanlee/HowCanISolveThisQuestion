// 희주의 수학시험
// https://www.acmicpc.net/problem/8974

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> v(1001);
	int t = 1, idx = 1;
	while (idx <= 1000) {
		for (int i = 1; i <= t; i++) {
			v[idx] = t;
			idx++;
			if (idx > 1000) {
				break;
			}
		}
		t++;
	}
	int a, b;
	cin >> a >> b;
	int res = 0;
	for (int i = a; i <= b; i++) {
		res += v[i];
	}
	cout << res << '\n';
}
 
// 1, 2, 2, 3, 3, 3... 순으로 주어진 수열에서 a~b번째 수의 합 구하기

// 수열 범위가 1000까지이므로 미리 만들어둔 뒤 풀 수 있음
// 그렇게 풀어줍니다