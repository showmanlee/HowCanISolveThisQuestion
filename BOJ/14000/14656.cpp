// 조교는 새디스트야!!
// https://www.acmicpc.net/problem/14656

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		if (p != i) {
			res++;
		}
	}
	cout << res << '\n';
}

// 수열이 주어질 때, i번째 수가 i가 아닌 경우 구하기

// 수들이 1부터 n까지 중복되서 주어지지 않음이 보장되므로 나오는 수가 i와 같은지 확인해보면 됨