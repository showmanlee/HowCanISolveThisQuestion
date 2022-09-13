// Checkers
// https://www.acmicpc.net/problem/21631

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long a, b;
	cin >> a >> b;
	long long res = min(a + 1, b);
	cout << res << '\n';
}

// 하얀색과 검정색 체커 말이 있고, 두 말을 교대로 쌓아 탑을 쌓을 떄, 들어갈 수 있는 검정색 말의 최대 개수는?

// n개의 검은 말을 모두 쌓기 위해서는 최소 n-1개의 하얀 말이 필요하다 - 시작을 검은 말로 할 수 있으므로
// 반대로 검은 말이 충분히 있을 때는 하얀 말이 n개일 때 n+1개의 검은 말을 사용할 수 있다
// 따라서 하얀 말+1, 검은 말 중 작은 개수가 답
// long long에 주의