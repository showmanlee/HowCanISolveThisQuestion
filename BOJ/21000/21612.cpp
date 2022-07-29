// Boiling Water
// https://www.acmicpc.net/problem/21612

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int p = 5 * n - 400;
    cout << p << '\n';
    cout << (p > 100 ? -1 : (p < 100 ? 1 : 0)) << '\n';
}

// 물이 끓은 온도가 주어졌을 때, 현재 기압(온도 * 5 - 400)과 100도보다 빨리 끓는지 늦게 끓는지 판정하기

// 계산하고, 비교하기 - 같거나(0) 크거나(-1), 작거나(1)