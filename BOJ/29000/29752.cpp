// 최장 스트릭
// https://www.acmicpc.net/problem/29752

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int streak = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        if (p == 0) {
            streak = 0;
        } else {
            streak++;
        }
        res = max(res, streak);
    }
    cout << res << '\n';
}

// 각 날짜에 푼 문제 수가 주어질 때, 최장 스트릭 구하기

// 0이 아닌 수가 연속으로 나온 횟수 구하기