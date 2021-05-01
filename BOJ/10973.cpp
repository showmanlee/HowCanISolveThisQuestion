// 이전 순열
// https://www.acmicpc.net/problem/10973

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
	if (prev_permutation(v.begin(), v.end())) {
		for (int i = 0; i < n; i++)
			cout << v[i] << ' ';
	}
	else
		cout << -1;
	cout << '\n';
}

// 주어진 순열의 이전 차례에 오는 순열은?
// next_permutation이 있다면 당연히 prev_permutation도 있습니다