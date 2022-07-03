// CCW
// https://www.acmicpc.net/problem/11758

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	int sine = (x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3) / 2;
    if (sine > 0) {
        cout << '1' << '\n';
	}
    else if (sine < 0) {
        cout << "-1" << '\n';
	}
    else {
        cout << '0' << '\n';
	}
}

// 2차원 좌표 위의 세 점을 순서대로 이었을 때 나오는 방향은?

// 벡터의 외적은 벡터가 나오고, 그 벡터의 크기는 a * b * sin이다 - 이 sin이 뻗은 방향을 보고 방향을 알 수 있다