// 수 정렬하기 4
// https://www.acmicpc.net/problem/11931

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
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < n; i++)
		cout << v[i] << '\n';
}

// 주어진 수열을 내림차순으로 정렬하기

// 그저 내림차순으로 정렬하면 되는 문제 - nlogn 알고리즘 써서
// 수 정렬하기 2와 문제 조건이 동일함