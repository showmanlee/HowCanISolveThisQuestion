// 체인
// https://www.acmicpc.net/problem/2785

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int res = 0;
	int idx = 0;
	n--;
	while (n > 0) {
		if (v[idx] <= n) {
			n -= v[idx] + 1;
			res += v[idx];
			idx++;
		} else {
			res += n;
			n = 0;
		}
	}
	cout << res << '\n';
}

// 체인의 개수와 각각의 체인의 길이가 주어질 떄, 하나의 긴 체인으로 만들기 위해 풀어야 하는 고리의 최소 수 구하기

// 기본적으로 체인 개수 - 1, 그러나 하나의 짧은 체인을 모두 사용한다면 그 체인을 연결할 고리는 필요가 없어짐
// 이를 이용하여 정렬 후 그리디로 풀어줄 수 있음