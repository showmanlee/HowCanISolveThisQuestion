// 미국 스타일
// https://www.acmicpc.net/problem/2712

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cout << fixed;
    cout.precision(4);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		double d;
		string s;
		cin >> d >> s;
		if (s == "kg") {
			d *= 2.2046;
			cout << d << " lb\n";
		} else if (s == "lb") {
			d *= 0.4536;
			cout << d << " kg\n";
		} else if (s == "l") {
			d *= 0.2642;
			cout << d << " g\n";
		} else if (s == "g") {
			d *= 3.7854;
			cout << d << " l\n";
		}
	}
}

// 주어진 수 만큼의 사각형이 겹친 형태의 별 출력하기

// 섬세한 반복문으로 출력할 수도 있고, 재귀로도 출력할 수 있음
// 어찌되었건 배열이 필요한 상황