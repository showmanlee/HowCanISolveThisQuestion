// 동전 0
// https://www.acmicpc.net/problem/11047

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;
	vector<int> coins(n);
	for (int i = 0; i < n; i++)
		cin >> coins[i];
	sort(coins.begin(), coins.end(), greater<int>());
	int res = 0;
	for (int i : coins) {
		res += k / i;
		k %= i;
	}
	cout << res << endl;
}

// C++11부터 생긴 신기능 - for(int i : coins)처럼 begin()이 있는 list를 foreach처럼 돌릴 수 있음
// 앞으로 자주 써먹어야지