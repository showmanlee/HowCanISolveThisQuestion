// ROOMS
// https://www.acmicpc.net/problem/3282

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, g;
    cin >> n >> g;
    int idx = 0;
    int remain = 0;
    vector<int> v(n);
    for (int t = 0; t < g; t++) {
        cin >> remain;
        while (remain > 0) {
            if (v[idx] != 2) {
                if (v[idx] == 0) {
                    v[idx] += (remain >= 2 ? 2 : 1);
                    remain -= (remain >= 2 ? 2 : 1);
                } else {
                    v[idx]++;
                    remain--;
                }
            }
            idx = (idx + 1) % n;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << v[i] << '\n';
    }
}

// 2인실 n개가 있는 호텔에서 일행을 받을 때 처음에는 1번 방부터 2명 + 홀수일 경우 1명 독방을, 그렇게 다 찼을 경우 1명 독방에 한 명씩 더 채울 때, 모든 방의 투숙 현황 출력하기

// 하면 됩니다 - 직잡 돌려보면서...