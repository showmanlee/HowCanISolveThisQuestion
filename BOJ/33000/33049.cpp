// 마작에서 가장 어려운 것
// https://www.acmicpc.net/problem/33049

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;
    bool pass = false;
    for (int i = 0; i <= c; i++) {
        if ((a + i) % 3 == 0 && (b + c - i) % 4 == 0) {
            cout << ((a + i) / 3) << ' ' << ((b + c - i) / 4) << '\n';
            pass = true;
            break;
        }
    }
    if (!pass) {
        cout << -1 << '\n';
    }
}

// 3인석 선호와 4인석 선호, 좌석 관계 없는 사람 수가 주어질 때, 3인석을 최소화하면서 모두 원하는 자리에 앉게 할 수 있는 3/4인석 수 구하기