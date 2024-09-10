// Last Factorial Digit
// https://www.acmicpc.net/problem/31048

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int i = 0; i < tt; i++) {
        int p;
        cin >> p;
        if (p >= 5) {
            cout << 0 << '\n';
        } else {
            int res = 1;
            for (int j = 1; j <= p; j++) {
                res = res * j % 10;
            }
            cout << res << '\n';
        }
    }
}

// 팩토리얼의 마지막 자릿수 구하기

// 5 이상인 경우 무조건 0