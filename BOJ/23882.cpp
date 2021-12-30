// 알고리즘 수업 - 선택 정렬 2
// https://www.acmicpc.net/problem/23882

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int swapped = 0;
	for (int i = n - 1; i >= 1; i--) {
		int maxi = 0;
		for (int j = 0; j <= i; j++) {
			if (v[j] > v[maxi]) {
				maxi = j;
			}
		}
		if (i != maxi) {
			swap(v[i], v[maxi]);
			swapped++;
			if (swapped == k) {
				for (int j = 0; j < n; j++) {
					cout << v[j] << ' ';
				}
				cout << '\n';
				break;
			}
		}
	}
	if (swapped < k) {
		cout << -1 << '\n';
	}
}

// 뒤에서부터 하는 선택 정렬 과정에서 k번째로 swap되는 시점의 배열 상태 출력하기

// 이미 수도 코드가 문제에 주어져 있으므로 수도 코드대로 정렬 코드를 만든 뒤, 그 안에서 swap 횟수를 센다
// 만약 k번째 swap이 이루어졌을 경우 배열 출력, k번째 swap이 발생하지 않은 경우 -1 출력