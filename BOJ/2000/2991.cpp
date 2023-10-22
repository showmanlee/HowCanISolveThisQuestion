// 사나운 개
// https://www.acmicpc.net/problem/2991

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> aa(1000), bb(1000);
    int as, ae, bs, be;
    cin >> as >> ae >> bs >> be;
    ae += as;
    be += bs;
    for (int i = 1; i < 1000; i++) {
        if (i % ae > 0 && i % ae <= as) {
            aa[i] = 1;
        }
        if (i % be > 0 && i % be <= bs) {
            bb[i] = 1;
        } 
    }
    int p, n, m;
    cin >> p >> n >> m;
    cout << (aa[p] + bb[p]) << '\n' << (aa[n] + bb[n]) << '\n' << (aa[m] + bb[m]) << '\n';
}

// 두 개의 경계/휴식 사이클 시간이 주어질 때, 세 사람이 각각 특정 시점에 개가 있는 곳에 들어갔을 때 공격하는 개의 수 구하기

// 계산을 해도 되지만, 시간 범위가 최대 1000까지이므로 배열을 만들어놓고 구해도 됨
// 근데 사실 배열 채우는 것도 계산 기반이라, 저 코드는 비효율적인 코드임 - 참고하세요