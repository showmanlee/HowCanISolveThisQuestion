// 수열 정렬
// https://www.acmicpc.net/problem/1015

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n), res(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	map<int, bool> used;
	for (int i = 0; i < n; i++) {
		int minx = 987654321, mini = -1;
		for (int j = 0; j < n; j++) {
			if (!used[j] && v[j] < minx) {
				minx = v[j];
				mini = j;
			}
		}
		res[mini] = i;
		used[mini] = true;
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << ' ';
	}
	cout << '\n';
}

// 주어진 수열을 비내림차순으로 정렬하기 위해 선택하는 순서 출력하기

// 수열 최대 길이가 1000이므로 n^2로 접근 가능
// 따라서 수열을 계속 돌면서 현재 선택되지 않은 (가장 앞에 있는) 가장 작은 수를 순서대로 계속 뽑아내는 식으로 처리 가능
// 이미 뽑힌 수는 map으로 관리, 결과는 배열로 출력