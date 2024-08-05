// 블로그2
// https://www.acmicpc.net/problem/20365

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int r = 0, b = 0;
    char prev = ' ';
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c != prev) {
            if (c == 'R') {
                r++;
            } else {
                b++;
            }
        }
        prev = c;
    }
    int res = 1 + min(r, b);
    cout << res << '\n';
}

// 주어진 리스트를 빨간색과 파란색으로 칠하는데 연속해서 칠할 수 있고 덮어칠할 수도 있을 때, 최소로 칠하는 개수 구하기

// 하나의 색깔로 모두 칠한 뒤, 남은 색깔을 칠해주면 됨
// 따라서 최솟값은 두 색깔의 덩어리 수의 최소 + 1