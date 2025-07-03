// 장인은 도구를 탓하지 않는다
// https://www.acmicpc.net/problem/25905

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	double res = 1, minn = 987654321;
	for (int i = 0; i < 10; i++) {
		double p;
		cin >> p;
		res *= p;
		minn = min(minn, p);
	}
	res *= 10000000000;
	res /= minn;

	cout << fixed;
	cout.precision(10);
	double ress = (double)res / 3628800;
	cout << ress << '\n';
}

// 각각의 확률이 있는 망치를 n번째 쓸 때의 확률이 pi/n일 때, 9번 사용해서 모두 성공할 수 있는 확률의 최댓값 구하기