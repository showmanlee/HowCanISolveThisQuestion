// 당구 좀 치자 제발
// https://www.acmicpc.net/problem/32642

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
    long long cnt = 0, res = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        cnt += (p == 1 ? 1 : -1);
        res += cnt;
    }
    cout << res << '\n';
}

// 1이 들어올 때 +1, 0이 들어올 때 -1이 되는 게이지가 주어질 때, 증감 현황에 따른 게이지값의 합 구하기