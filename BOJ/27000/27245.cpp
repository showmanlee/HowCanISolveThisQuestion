// Комната
// https://www.acmicpc.net/problem/27245

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    double w, l, h;
    cin >> w >> l >> h;
    bool res = (min(w, l) / h) >= 2.0 && max(w, l) / min(w, l) <= 2.0;
    cout << (res ? "good" : "bad") << '\n';
}

// 방의 가로 세로 높이가 주어질 때, 가로 세로 중 짧은 쪽과 높이의 비가 2 이상이고 가로 세로 중 긴 쪽과 짧은 쪽의 비가 2 이하인지 확인하기

// 계산 계산 계산 - 언어가 어렵지 문제는 쉽다