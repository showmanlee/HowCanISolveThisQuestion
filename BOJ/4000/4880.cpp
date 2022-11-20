// 다음수
// https://www.acmicpc.net/problem/4880

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) {
			break;
		}
		if (a - b == b - c) {
			cout << "AP " << c + (b - a) << '\n';
		} else {
			cout << "GP " << c * (b / a) << '\n';
		}
	}
}

// 주어진 세 수의 관계가 등차수열인지 등비수열인지 판정하고 다음에 올 수 구하기

// 세 수가 수열 관계임이 보장되므로 마주보는 두 수의 차가 같으면 등차, 아니면 등비
// 만약 등차라면 c에 두 수의 차를 더하고, 등비라면 두 수를 나눈 값을 곱한다