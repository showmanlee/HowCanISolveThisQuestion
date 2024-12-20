// Attention to the Meeting
// https://www.acmicpc.net/problem/32432

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    int res = (k - n + 1) / n;
    cout << res << '\n';
}

// n명이 k분 동안 1분 휴식시간을 두고 모두 같은 시간 동안 말할 수 있는 인당 최대 시간 구하기