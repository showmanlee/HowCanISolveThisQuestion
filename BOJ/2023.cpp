// 신기한 소수
// https://www.acmicpc.net/problem/2023

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;

bool prime(int p) {
	for (int i = 2; i <= sqrt(p); i++)
		if (p % i == 0)
			return false;
	return true;
}

void dfs(int p, int l) {
	if (l == n) {
		cout << p << '\n';
		return;
	}
	for (int i = 1; i <= 9; i += 2) {
		if (prime(p * 10 + i))
			dfs(p * 10 + i, l + 1);
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	dfs(2, 1);
	dfs(3, 1);
	dfs(5, 1);
	dfs(7, 1);
}

// n자리 수 중에서 왼쪽부터 1~n자리를 뗀 수들이 모두 소수인 수는?

// 일단 메모리가 4MB밖에 없으므로 에라토스테네스를 사용할 수는 없음 - 직접 판정 필요
// 그렇다고 n자리 수를 모두 탐색하기에는 시간 초과 가능성 높음
// 그렇다면 해답은 dfs를 활용해 숫자를 만들어나가는 것 - 한 자리부터 소수를 만들어나가다가, n자리에 도달하면 출력
// 그렇다고 모든 수를 탐색할 수는 없으니 경우의 수를 줄여야 함 - 2, 3, 5, 7로만 시작, 이후 자릿수를 추가한 수는 홀수여야 함
// 진입하기 전 만든 수가 소수가 아니라면 진입하지 않기 - 소수 판정은 2부터 sqrt(n)까지 나머지를 모두 넣어보는 고전적 방식으로 구현
// 이렇게 n자리까지 진입하면 우리가 원하는 수가 나옴