// 신을 모시는 사당
// https://www.acmicpc.net/problem/27210

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int res = 1;
    vector<int> dpl(n), dpr(n);
    dpl[0] = dpr[0] = 1;
    for (int i = 0; i < n; i++) {
        int p = v[i] == 1 ? -1 : 1;
        int q = v[i] == 2 ? -1 : 1;
        if (i == 0) {
            dpl[i] = p;
            dpr[i] = q;
        } else {
            dpl[i] = max(dpl[i - 1] + p, p);
            dpr[i] = max(dpr[i - 1] + q, q);
        }
        res = max(res, dpl[i]);
        res = max(res, dpr[i]);
    }
    cout << res << '\n';
}

// 좌우를 보고 있는 일렬로 놓인 불상에서 연속으로 몇개를 골라 얻을 수 있는 | 왼쪽 - 오른쪽 |의 최댓값 구하기

// 왼쪽을 +1, 오른쪽을 -1로 보고 순회하면서 dp로 점수 계산 - 절댓값이므로 반대 방향으로도 해줘야 함