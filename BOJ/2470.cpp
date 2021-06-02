// 두 용액
// https://www.acmicpc.net/problem/2470

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	int left = 0, right = n - 1;
	int res = 2100000000;
	int a = -1, b = -1;
	while (left < right) {
		int p = v[left] + v[right];
		if (abs(p) < res) {
			res = abs(p);
			a = v[left];
			b = v[right];
		}
		if (p < 0)
			left++;
		else
			right--;
	}
	cout << a << ' ' << b << '\n';
}

// 특성값이 다른 용액 2개를 혼합해 만들 수 있는 용액의 절댓값이 최소가 나오는 용액의 특성값 (아무거나) 출력하기

// 2467 용액에서 용액 배열이 정렬되지 않은 상태로 제공되는 버전
// 따라서 2467 코드에서 정렬만 구현하면 됨 - 만약 본능적으로 정렬을 구현했다면, 같은 코드가 됨