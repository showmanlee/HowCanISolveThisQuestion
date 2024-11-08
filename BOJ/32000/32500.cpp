// Dishonest Lottery
// https://www.acmicpc.net/problem/32500

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> cnt(51);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 50; j++) {
            int p;
            cin >> p;
            cnt[p]++;
        }
    }
    bool res = false;
    for (int i = 1; i <= 50; i++) {
        if (cnt[i] > n * 2) {
            cout << i << ' ';
            res = true;
        }
    }
    if (!res) {
        cout << -1;
    }
    cout << '\n';
}

// 50n개의 수가 등장할 때, 2n개 넘게 등장한 수 구하기