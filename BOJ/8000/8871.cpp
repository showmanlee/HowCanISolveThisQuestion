// Zadanie próbne 2
// https://www.acmicpc.net/problem/8871

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	n++;
	cout << (n * 2) << ' ' << (n * 3) << '\n';
}

// 주어진 수 n에 대해 (n+1)*2, (n+1)*3 구하기

// 구합시다