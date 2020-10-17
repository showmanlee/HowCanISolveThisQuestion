// 숫자 카드 2
// https://www.acmicpc.net/problem/10816

#include <iostream>
#include <algorithm>
using namespace std;
int num[500001];

int lower(int n, int p) {
	int min = 0, max = n - 1;
	while (max > min) {
		int mid = (min + max) / 2;
		if (num[mid] >= p)
			max = mid;
		else
			min = mid + 1;
	}
	return max;
}

int upper(int n, int p) {
	int min = 0, max = n - 1;
	while (max > min) {
		int mid = (min + max) / 2;
		if (num[mid] > p)
			max = mid;
		else
			min = mid + 1;
	}
	return max;
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
		int l = lower(n, p);
		int u = upper(n, p);
		if (u == n - 1 && num[u] == p)
			u++;
		cout << (u - l) << ' ';
	}
	cout << '\n';
}

// map을 사용하면 타임아웃
// 정렬한 후 이진탐색으로 위치 잡고 카운팅해야 함
// 여기서 위치 잡는 방법은 찾고자하는 값 이하의 값이 나오는 곳(lower), 초과의 값이 나오는 곳(upper)의 인덱스를 잡고 두 인덱스를 뺴면 됨
// 여기서 upper가 끝부분인데 찾고자 하는 값이 끝부분에 있다면 잘못된 결과가 나오니 upper++해야 함
// 그 외에도 500000개라서 극한의 다이어트 필요(vector 대신 일반 배열 사용, cstdio 또는 입출력 특수문 적용)