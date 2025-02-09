// 코드마스터 2024
// https://www.acmicpc.net/problem/32215

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	int res = m * (k + 1);
	cout << res << '\n';
}

// n개의 컴퓨터에 에디터를 m개씩 설치하는데 k개의 컴퓨터에는 일일히 m개씩, 그 외의 컴퓨터는 매크로로 하나의 컴퓨터에 m개 설치했을 때 총 설치 횟수 구하기