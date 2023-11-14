// 구와 쿼리 
// https://www.acmicpc.net/problem/13552

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Point {
    long long x;
    long long y;
    long long z;
} point;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y >> points[i].z;
    }
    int m;
    cin >> m;
    for (int t = 0; t < m; t++) {
        int res = 0;
        long long xx, yy, zz, r;
        cin >> xx >> yy >> zz >> r;
        for (point p : points) {
            long long xl = xx - p.x;
            long long yl = yy - p.y;
            long long zl = zz - p.z;
            if (xl * xl + yl * yl + zl * zl <= r * r) {
                res++;
            }
        }
        cout << res << '\n';
    }
}

// 주어진 점들 중 주어진 구들 안이나 경계에 들어가는 점 개수 구하기

// 갯수가 꽤 많지만 n^2로 구할 수밖에 없음 - 다행히 제한시간 20초라서 여유는 있음