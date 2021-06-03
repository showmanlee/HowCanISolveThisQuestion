// 세 용액
// https://www.acmicpc.net/problem/2473

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
	vector<long long> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	long long res = 3100000000;
	int a = -1, b = -1, c = -1;
	for (int i = 0; i < n - 2; i++) {
		int left = i + 1, right = n - 1;
		while (left < right) {
			long long p = v[left] + v[right] + v[i];
			if (abs(p) < res) {
				res = abs(p);
				a = v[i];
				b = v[left];
				c = v[right];
			}
			if (p < 0)
				left++;
			else
				right--;
		}
	}
	cout << a << ' ' << b << ' ' << c <<  '\n';
}

// 특성값이 다른 용액 3개를 혼합해 만들 수 있는 용액의 절댓값이 최소가 나오는 용액의 특성값 (아무거나) 출력하기

// 당연히 n^3으로 푸는 문제는 아님 - 두 용액 문제에서는 이분탐색을 썼었음
// 세 용액을 고르는 과정에서도 이분탐색을 사용할 수 있음 - 첫 값을 for로 정하고, 그 다음부터 마지막까지를 이분탐색 범위로 활용하기
// 이렇게 해도 결과적으로 가능한 모든 경우의 수를 탐색할 수 있음 - 첫 값만 정해진 상태고, 그 첫 값에 대응하는 최적의 해를 이분탐색으로 찾음