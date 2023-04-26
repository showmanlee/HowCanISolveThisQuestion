// Triangle Height
// https://www.acmicpc.net/problem/26592

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cout << fixed;
    cout.precision(2);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		float a, b;
		cin >> a >> b;
		cout << "The height of the triangle is " << (a / b * 2) << " units\n";
	}
}

// 삼각형의 넓이와 밑변이 주어질 때, 높이 구하기

// 밑변 * 높이 / 2 = 넓이
// 이를 이항하면 높이 = 넓이 / 밑변 * 2