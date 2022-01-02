// 분산처리
// https://www.acmicpc.net/problem/1009

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int a, b;
		cin >> a >> b;
		int r = 1;
		for (int i = 0; i < b; i++)
			r = (r * a) % 10;
		if (r == 0)
			r = 10;
		cout << r << '\n';
	}
}

// a^b개의 작업을 10대의 컴퓨터가 순서대로 분산 처리할 때, 마지막 데이터를 처리하는 컴퓨터는?
// 최대 100^1000000이므로 직접 계산할 수는 없고, 나머지 연산 기반으로 구해야 함
// 마침 컴퓨터 수가 10개이니, a^b의 마지막 자리를 구하는 문제와 같다고 볼 수 있음 - 0은 10으로 출력하고