// Ratownik
// https://www.acmicpc.net/problem/8574

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    double r, a, b;
    cin >> r >> a >> b;
    int res = 0;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        if ((x - a) * (x - a) + (y - b) * (y - b) > r * r) {
            res++;
        }
    }
    cout << res << '\n';
}

// 2차원 좌표공간의 n개의 점 중  (a,b)를 중심으로 하는 반지름 r 바깥의 점 개수 구하기