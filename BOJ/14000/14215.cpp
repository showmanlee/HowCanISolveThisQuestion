// 세 막대
// https://www.acmicpc.net/problem/14215

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;
	if (a > b) {
		swap(a, b);
	}
	if (a > c) {
		swap(a, c);
	}
	if (b > c) {
		swap(b, c);
	}
	if (a + b > c) {
		cout << (a + b + c) << '\n';
	}
	else {
		cout << (a + b + (a + b - 1)) << '\n';
	}
}

// 삼각형을 구성할 세 막대기의 길이가 주어지고, 각 막대기의 길이를 줄일 수 있을 때, 만들 수 있는 삼각형의 최대 둘레 출력하기

// 삼각형이 구성되려면 가장 긴 변의 길이가 다른 변 길이의 합보다 짧아야 한다
// 따라서 세 변을 정렬해 저 상황이 맞는 경우 그대로 쓰면 되고, 그렇지 않은 경우 가장 긴 변을 두 변의 합 - 1로 줄여 써야 한다