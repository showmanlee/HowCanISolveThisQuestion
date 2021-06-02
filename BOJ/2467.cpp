// 용액
// https://www.acmicpc.net/problem/2467

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

// 당연히 n^2로 푸는 문제는 아님 - 이분탐색
// 평소와 같이 이분탐색을 돌리는데, 만약 두 용액의 합의 절댓값이 결과값 미만이라 갱신이 필요한 경우 해당 값으로 결과값을 갱신하고, 출력할 두 용액도 저장하기
// 이후 두 용액의 합이 0 미만이면 left++, 그렇지 않다면 right-- - 절댓값을 최소로 만들어야 하기에 음수면 값을 늘려야 하고, 양수면 값을 줄여야 한다

// solved.ac CLASS 5 진입! - 그래서 Platinum 4도 진입!
// 다음은 900문제 진입, 그리고 1000문제 진입 전 Platinum 3 진입!