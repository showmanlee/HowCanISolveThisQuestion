// 게임을 만든 동준이
// https://www.acmicpc.net/problem/2847

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
	int res = 0;
	for (int i = n - 2; i >= 0; i--) {
		while (v[i] >= v[i + 1]) {
			v[i]--;
			res++;
		}
	}
	cout << res << '\n';
}

// 주어진 수열의 원소를 모두 자연수로 유지하면서 오름차순으로 만들기 위해 필요한 -1 연산의 최소 횟수 구하기

// 뒤에서부터 돌면서 바로 뒤의 원소보다 1 작도록 만들면 됨 - 그보다 더 작으면 그대로 두고
// 여기서는 빼는 연산만 할 수 있고, 항상 답이 있는 경우만 주어짐 - 이를 감안하며 작성해봅시다