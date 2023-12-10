// Санта Клаус
// https://www.acmicpc.net/problem/19963

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> v(n + 1, true);
    int res = n;
    for (int i = 0; i < m; i++) {
        int p;
        cin >> p;
        if (v[p]) {
            v[p] = false;
            res--;
        }
    }
    for (int i = 0; i < k; i++) {
        int p;
        cin >> p;
        if (v[p]) {
            v[p] = false;
            res--;
        }
    }
    cout << res << '\n';
    for (int i = 1; i <= n; i++) {
        if (v[i]) {
            cout << i << ' ';
        }
    }
}

// 1~n번의 아이에게 줄 선물이 2개의 가방에 있을 때, 두 가방에 있는 선물을 받지 못하는 아이들의 번호 출력하기

// 가방 안에서 등장하지 않는 번호 찾아 출력하기