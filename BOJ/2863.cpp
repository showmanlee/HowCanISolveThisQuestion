// 이게 분수?
// https://www.acmicpc.net/problem/2863

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<double> v(4);
	cin >> v[0] >> v[1] >> v[3] >> v[2];
	double max = 0;
	int res = -1;
	for (int i = 0; i < 4; i++) {
		double d = v[0] / v[3] + v[1] / v[2];
		if (max < d) {
			max = d;
			res = i;
		}
		double temp = v[3];
		v[3] = v[2];
		v[2] = v[1];
		v[1] = v[0];
		v[0] = temp;
	}
	cout << res << '\n';
}

// 2*2 배열의 윗줄을 분자, 아랫줄을 분모로 하여 더한 값을 최대로 만들기 위해 시계방향으로 90도 회전해야 하는 횟수는?
// 실제로 돌려보면서 계산해보기 - 배열을 0, 1, 3, 2 순서로 받아서 선형적으로 돌아갈 수 있게