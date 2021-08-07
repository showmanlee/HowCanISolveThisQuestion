// 수 정렬하기 5
// https://www.acmicpc.net/problem/15688

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
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
		cout << v[i] << '\n';
}

// 주어진 수열을 비내림차순으로 정렬하기

// 수 정렬하기 2와 문제 조건이 동일함 - 다만 이번에는 중복수가 나올 수 있음
// 또한 '시간 누적' 문제임 - 모든 테케 시간이 누적되어 10초 시간 제한
// 그래도 수 정렬하기 2 코드 - nlogn 알고리즘이면 해결 가능