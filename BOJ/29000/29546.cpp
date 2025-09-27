// Файлы
// https://www.acmicpc.net/problem/29546

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<string> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = a; j <= b; j++) {
			cout << v[j] << '\n';
		}
	}
}

// 주어진 문자열들을 주어진 범위 순서대로 출력하기