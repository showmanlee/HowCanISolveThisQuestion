// 국방시계
// https://www.acmicpc.net/problem/33277

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	double n, m;
	cin >> n >> m;
	int d = m / n * 1440;
	cout.width(2);
	cout.fill('0');
	cout << (d / 60) << ":";
	cout.width(2);
	cout.fill('0');
	cout << (d % 60) << '\n';
}

// n일 중 m일을 보냈을 때, 진행도를 24시간으로 표시한 결과 출력하기