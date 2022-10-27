// 서버
// https://www.acmicpc.net/problem/10409

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	int sum = 0, res = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		sum += p;
		if (sum <= m) {
			res++;
		}
	}
	cout << res << '\n';
}


// FCFS 방식의 서버에서 일들이 주어졌을 때, 주어진 시간 내에 할 수 있는 일의 양은?

// 앞에서부터 시간을 더해보며 시간 이하라면 할 수 있는 일