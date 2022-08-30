// 황소 다마고치
// https://www.acmicpc.net/problem/23323

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		long long n, m;
		cin >> n >> m;
		long long res = 0;
		while (n > 0) {
			n /= 2;
			res++;
		}
		res += m;
		cout << res << '\n';
	}
}

// 매일 밤에 체력이 절반(소수점 버림)씩 떨어지는 황소에게 매일 낮 먹이를 하나 주어 체력을 1 회복시킬 수 있을 때, 황소를 가장 오래 살릴 수 있는 기간은?

// 체력이 얼마나 남았든 결과적으로 죽기 직전 황소의 체력은 1이 된다 - 그리고 여기서 먹이 하나를 주면 체력이 2가 되어 하루 더 살 수 있게 된다
// 이 2->1->2->1 사이클을 최대로 활용하면 황소를 가장 오랫동안 살릴 수 있다 - 먹이 하나 당 하루를 살릴 수 있음
// 따라서 답은 주어진 체력을 계속 2로 나눠서 0이 되는 횟수 + 먹이 개수