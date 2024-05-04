// Knob
// https://www.acmicpc.net/problem/30617

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int l, r;
    cin >> l >> r;
    int res = (l != 0 && l == r ? 1 : 0);
    for (int i = 1; i < n; i++) {
        int ll, rr;
        cin >> ll >> rr;
        if (ll != 0 && ll == rr) {
            res++;
        }
        if (ll != 0 && l == ll) {
            res++;
        }
        if (rr != 0 && r == rr) {
            res++;
        }
        l = ll;
        r = rr;
    }
    cout << res << '\n';
}

// 양쪽 노브를 돌리는 순서가 주어지고, 여기서 양쪽 노브를 동시에 같은 방향으로 돌리거나, 한쪽 노브를 이전과 같은 방향으로 다시 돌릴 때 1점씩 오를 때, 최종 점수 구하기

// 앞에서부터 입력받으며 구해보자