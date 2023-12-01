// Flat
// https://www.acmicpc.net/problem/3512

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cout << fixed;
	cout.precision(6);

    int n, m;
    cin >> n >> m;
    double count = 0;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        double a;
        string s;
        cin >> a >> s;
        if (s == "balcony") {
            count += a / 2;
        } else {
            count += a;
        }
        x += a;
        if (s == "bedroom") {
            y += a;
        }
    }
    cout << x << '\n' << y << '\n' << (count * m) << '\n';
}

// 집 구조와 각 공간의 넓이가 주어지고, 아파트의 비용은 (단위면적당 비용 * (발코니 제외 모든 방 넓이 + (모든 발코니 넓이 / 2)))일 때, 아파트 전체 넓이, 침실 넓이, 최종 비용 구하기

// 시키는 대로 구해주면 됩니다 - 실수 계산이 됨에 주의