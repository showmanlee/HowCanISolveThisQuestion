// Gift
// https://www.acmicpc.net/problem/9848

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, t;
    cin >> n >> t;
    int prev;
    cin >> prev;
    int res = 0;
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        if (prev - p >= t) {
            res++;
        }
        prev = p;
    }
    cout << res << '\n';
}

// 매일의 기록이 주어질 때, 전날과의 기록차가 p 이상인 경우 구하기

// 순서대로 받으며 구합시다