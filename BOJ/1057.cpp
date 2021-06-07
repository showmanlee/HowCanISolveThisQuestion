// 토너먼트
// https://www.acmicpc.net/problem/1057

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, a, b;
	cin >> n >> a >> b;
	int res = -1, cnt = 1;
	while (n > 0) {
		if ((a + 1) / 2 == (b + 1) / 2) {
			res = cnt;
			break;
		}
		cnt++;
		n /= 2;
		a = (a + 1) / 2;
		b = (b + 1) / 2;
	}
	cout << res << '\n';
}

// 처음에 마주한 번호끼리 붙는 토너먼트 대진표에서 두 참가자의 첫 번호가 주어졌을 때, 만나게 되는 라운드 번호는?

// 한 참가자가 다음 라운드에 진출할 경우, 그 사람은 다음 라운드에서 (n + 1) / 2번을 받게 된다 - (1 + 1) / 2 == (2 + 1) / 2
// 이를 활용하여 두 참가자 번호를 받고 둘이 같아질 때까지 계속 올라가면서 라운드를 누적하다가, 다음 라운드에 둘의 번호가 같아지면 현재 라운드를 출력
// 물론 만나지 않을 수도 있음(-1) - 이것은 전체 참가자 수를 라운드가 바뀔 때마다 /2하여 0이 되었음에도 만나지 않는 것으로 알 수 있음