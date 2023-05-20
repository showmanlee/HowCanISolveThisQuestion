// Kuber
// https://www.acmicpc.net/problem/20833

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res += i * i * i;
	}
	cout << res << '\n';
}

// 한 변의 길이가 1부터 n까지인 정육면체를 만드는데 필요한 1*1*1 정육면체의 개수는?

// 1부터 n까지 i^3을 구한다