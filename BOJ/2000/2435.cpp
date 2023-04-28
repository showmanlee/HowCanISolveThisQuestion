// 기상청 인턴 신현수
// https://www.acmicpc.net/problem/2435

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	int sum = 0;
	int res = 0;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < k; i++) {
		sum += v[i];
	}
	res = sum;
	for (int i = k; i < n; i++) {
		sum += v[i];
		sum -= v[i - k];
		res = max(res, sum);	
	}
	cout << res << '\n';
}

// 주어진 배열에서 연속된 k개의 수의 합이 가장 큰 경우 구하기

// 슬라이딩 윈도우의 기본 - n^2로 풀어도 되고