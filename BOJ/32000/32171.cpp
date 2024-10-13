// 울타리 공사
// https://www.acmicpc.net/problem/32171

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int minx = 987654321, miny = 987654321, maxx = -987654321, maxy = -987654321;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        minx = min(minx, a);
        miny = min(miny, b);
        maxx = max(maxx, c);
        maxy = max(maxy, d);
        int res = (maxx - minx) * 2 + (maxy - miny) * 2;
        cout << res << '\n';
    }
}

// 2차원 공간에서 사각형을 계속 그릴 때, 그린 모든 사각형을 감싸는 축에 평행한 직사각형 둘레 길이 구하기