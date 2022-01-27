// 短針 (Hour Hand) 
// https://www.acmicpc.net/problem/24083

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	cout << ((a + b - 1) % 12 + 1) << '\n';
}

// 현재 시가 주어질 때, b시간 뒤 시를 12시간 단위로 출력하기

// (a - 1 + b) % 12 + 1
// -1은 나머지 연산을 위해 1~12 스케일을 0~11 스케일로 바꾸는 작업, +1은 그 반대