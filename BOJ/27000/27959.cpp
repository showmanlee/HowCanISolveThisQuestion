// 초코바
// https://www.acmicpc.net/problem/27959

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	cout << (n * 100 >= m ? "Yes" : "No") << '\n';
}

// 100원 동전 n개로 m원짜리 초코바를 사먹을 수 있는지 구하기

// n * 100 >= m