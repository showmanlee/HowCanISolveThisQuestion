// Hezardastan’s Annual Report
// https://www.acmicpc.net/problem/33179

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		p++;
		res += p / 2;
	}
	cout << res << '\n';
}

// 각 섹션의 페이지 수가 주어질 때, 양면 인쇄 환경에서 서로 다른 섹터가 한 장에 인쇄되지 않게 인쇄하는데 필요한 장 수 구하기