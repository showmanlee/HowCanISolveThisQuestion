// 포인트 카드
// https://www.acmicpc.net/problem/14471

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = a;
    }
    sort(v.begin(), v.end(), greater<int>());
    int res = 0;
    for (int i = 0; i < m - 1; i++) {
        if (v[i] <= n) {
            res += n - v[i];
        }
    }
    cout << res << '\n';
}

// 2n개의 칸이 있는 쿠폰에 n개 이상의 당첨 도장이 찍혀야 하는 상황에서 1원을 주고 도장 칸 하나를 바꿀 수 있을 때, m개의 쿠폰 중 m-1개의 쿠폰을 당첨 상태로 만들기 위해 필요한 최소 금액 구하기

// 당첨 적힌 순으로 내림차순으로 정렬한 후, 맨 마지막을 제외한 모든 쿠폰에서 부족한 당첨 수만큼 채워넣기