// 초콜릿 자르기
// https://www.acmicpc.net/problem/2163

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	int res = (n * m) - 1;
	cout << res << '\n';
}

// n*m조각으로 나눌 수 있는 초콜릿을 1*1 크기의 조각으로 만드는데 필요한 최소 쪼개기 횟수는?

// 그러니까 가로로 n-1개, 세로로 m-1개의 금이 있는 초콜릿이란 말
// 그 금대로 초콜릿을 잘라줘야 한다 - 가로로 n-1번 자르고, 그 잘린 조각들에 대해 세로로 m-1번 잘라야 한다(동시에 자를 수는 없음)
// 이를 식으로 나타내면 n - 1 + n(m - 1)이 되는데, 이는 n - 1 + nm - n = 1 + nm과 같다
// 따라서 nm - 1이 답