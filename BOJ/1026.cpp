// 보물
// https://www.acmicpc.net/problem/1026

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());
	int res = 0;
	for (int i = 0; i < n; i++)
		res += a[i] * b[i];
	cout << res << '\n';
}

// 정수가 적힌 크기가 같은 두 배열 중 하나의 배열만 원소를 재배치하여 같은 위치에 있는 원소를 곱한 것의 합을 최소로 만든 값 출력하기

// 큰 수에는 최대한 작은 수를 곱해야 최소의 결과를 얻을 수 있다 - 이를 위해 a는 오름차순, b는 내림차순으로 정렬한 뒤 결과를 얻으면 됨
// b는 정렬할 수 없다고 나와 있지만, 어쨌든 a의 모든 수가 b와 매칭될 수 있으므로 이렇게 해도 결과는 같음