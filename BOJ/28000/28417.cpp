// 스케이트보드
// https://www.acmicpc.net/problem/28417

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        vector<int> v(5);
        int a, b;
        cin >> a >> b;
        for (int j = 0; j < 5; j++) {
            cin >> v[j];
        }
        sort(v.begin(), v.end());
        res = max(res, max(a, b) + v[4] + v[3]);
    }
    cout << res << '\n';
}

// 런 2회에서 더 높은 점수, 트릭 5회에서 상위 2개 점수의 합으로 승부를 볼 때, 주어진 점수 기록 중 가장 높은 점수 구하기

// 정렬 및 비교로 계산해보아요