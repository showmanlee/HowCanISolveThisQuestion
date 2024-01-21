// 공 포장하기
// https://www.acmicpc.net/problem/12981

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int r, g, b;
    cin >> r >> g >> b;
    int res = min(r, min(g, b));
    r -= res;
    g -= res;
    b -= res;
    res += r / 3 + g / 3 + b / 3;
    r %= 3;
    g %= 3;
    b %= 3;
    if (r == 2) {
        res++;
        r = 0;
    }
    if (g == 2) {
        res++;
        g = 0;
    }
    if (b == 2) {
        res++;
        b = 0;
    }
    if (r + g + b > 0) {
        res++;
    }
    cout << res << '\n';
}

// 주어진 3가지 색깔 공을 서로 다르거나 같은 색으로 한 상자에 3개까지 채울 수 있을 떄, 모든 공을 상자에 담는데 필요한 상지의 최소 수 구하기

// 서로 다른 거 3개 -> 서로 같은 거 3개 -> 서로 같은 거 2개 -> 서로 다른 거 1~2개 순으로 넣어주기