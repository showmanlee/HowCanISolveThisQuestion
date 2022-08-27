// Square Pasture
// https://www.acmicpc.net/problem/14173

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int maxx = max(x1, max(x2, max(x3, x4)));
    int maxy = max(y1, max(y2, max(y3, y4)));
    int minx = min(x1, min(x2, min(x3, x4)));
    int miny = min(y1, min(y2, min(y3, y4)));
    int p = max(maxx - minx, maxy - miny);
    cout << (p * p) << '\n';
}

// 두 개의 직사각형 우리가 주어질 때 이 둘을 모두 커버하는 정사각형 우리의 넓이 중 가장 작은 값은?

// 두 우리의 통합 가로폭과 세로폭을 구한 다음 두 폭 중 더 긴 쪽을 정사각형의 한 변으로 잡는다