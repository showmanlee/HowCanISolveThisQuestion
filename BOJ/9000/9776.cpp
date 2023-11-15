// Max Volume
// https://www.acmicpc.net/problem/9776

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cout << fixed;
    cout.precision(3);

    int n;
    cin >> n;
    double res = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        double p;
        if (c == 'C') {
            double r, h;
            cin >> r >> h;
            p = (1.0 / 3.0) * 3.14159 * r * r * h;
        } else if (c == 'L') {
            double r, h;
            cin >> r >> h;
            p = 3.14159 * r * r * h;
        } else if (c == 'S') {
            double r;
            cin >> r;
            p = (4.0 / 3.0) * 3.14159 * r * r * r;
        }
        res = max(res, p);
    }
    cout << res << '\n';
}

// 주어진 원뿔, 원기둥, 구의 부피 중 가장 큰 값 구하기

// 공식에 맞춰 계산한 후, 최댓값을 구해 소수 셋쨰자리까지 출력한다