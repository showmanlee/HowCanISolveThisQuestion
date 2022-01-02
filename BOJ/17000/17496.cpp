// 스타후르츠
// https://www.acmicpc.net/problem/17496

#include <iostream>
using namespace std;

int main(void) {
	int n, t, c, p;
	cin >> n >> t >> c >> p;
	cout << ((n - 1) / t * c * p) << '\n';
}

// n일의 여름 동안 t일 만에 자라는 개당 p원짜리 스타후르츠를 c개 심을 수 있는 밭에 최대한 심을 때 벌 수 있는 돈은?
// 여름이 1일부터 시작됨에 주의