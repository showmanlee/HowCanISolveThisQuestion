// 수 찾기
// https://www.acmicpc.net/problem/1920

#include <iostream>
#include <algorithm>
using namespace std;
int num[100001];

bool finder(int n, int p) {
	int min = 0, max = n - 1;
	while (min <= max) {
		int mid = (min + max) / 2;
		if (num[mid] == p)
			return true;
		else if (num[mid] > p) 
			max = mid - 1;
		else 
			min = mid + 1;
	}
	return false;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	sort(num, num + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int p;
		cin >> p;
		cout << finder(n, p) << '\n';
	}
}

// 100,000개를, 그것도 여러 번 찾는 거라 단순 탐색으로는 타임아웃 가능성 존재
// 정렬하고 이분탐색으로 찾는게 더 빠름
// 일반 배열을 쓰면 속도를 더 높일 수 있음
// 거기에 cin.tie(NULL)과 ios_base::sync_with_stdio(false)를 적용해주니 바로 붙더라