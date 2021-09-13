// 주디와 당근농장
// https://www.acmicpc.net/problem/16433

#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, r, c;
	cin >> n >> r >> c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << ((i % 2 == r % 2) ^ (j % 2 != c % 2) ? 'v' : '.');
		cout << '\n';
	}
}

// n*n 밭중 한 칸에 당근을 이미 심었을 때, 당근을 서로 맞닿게 심지 않고 최대로 심는 방법은?

// 체스판처럼 놓으면 됨 - 기준점과 열/행 번호 % 2가 모두 같거나 모두 다르면 놓기
// xor를 사용하여 R ^ !C로 계산