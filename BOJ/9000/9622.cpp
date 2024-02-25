// Cabin Baggage
// https://www.acmicpc.net/problem/9622

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        double l, w, h, g;
        cin >> l >> w >> h >> g;
        if (((l <= 56 && w <= 45 && h <= 25) || ((l + w + h) <= 125)) && g <= 7) {
            cout << 1 << '\n';
            res++;
        } else {
            cout << 0 << '\n';
        }
    }
    cout << res << '\n';
}

// 가방의 길이가 56, 너비가 45, 깊이가 25를 넘기지 않거나 세 변을 합쳐 125를 넘기면 안 되고, 무게가 7을 넘기면 안 될 때 각 가방의 가능 여부와 가능한 가방 수 구하기