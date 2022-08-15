// Identifying tea
// https://www.acmicpc.net/problem/11549

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    int res = 0;
    for (int i = 1; i <= 5; i++) {
        int p;
        cin >> p;
        if (t == p) {
            res++;
        }
    }
    cout << res << '\n';
}

// 정답과 5명이 쓴 답안이 주어질 때, 맞은 사람 수 출력하기

// 보고 세서 출력하면 됩니다...