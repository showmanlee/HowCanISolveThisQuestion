// 구구단표
// https://www.acmicpc.net/problem/32710

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (i * j == n) {
                res = 1;
            }
        }
    }
    cout << res << '\n';
}

// 주어진 수가 구구단표에서 나오는지 구하기