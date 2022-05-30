// 정열적인 정렬
// https://www.acmicpc.net/problem/16212

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
	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}
	cout << '\n';
}

// 주어진 수열 정렬하기

// nlogn 알고리즘으로 정렬해보는 문제 - 병합/퀵정렬을 써야겠지
// 하지만 우리에게는 std::sort가 있으니 그걸 써먹으면 됨 - 문제에서도 그러라고 하고