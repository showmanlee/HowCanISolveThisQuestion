// 대각선
// https://www.acmicpc.net/problem/34346

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cout << (n % 2 == 1 ? 1 : 2) << '\n';
}

// n*n 보드에 양쪽 대각선에 모두 색을 넣기 위해 필요한 개수 구하기