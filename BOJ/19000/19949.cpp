// 영재의 시험
// https://www.acmicpc.net/problem/19949

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int answer[10], v[10];
int res = 0;

void f(int idx, int score) {
    if (idx == 10) {
        if (score >= 5) {
            res++;
        }
        return;
    }
    int exclude = -1;
    if (idx >= 2 && v[idx - 1] == v[idx - 2]) {
        exclude = v[idx - 1];
    }
    for (int i = 1; i <= 5; i++) {
        if (exclude == i) {
            continue;
        }
        v[idx] = i;
        if (i == answer[idx]) {
            score++;
        }
        f(idx + 1, score);
        if (i == answer[idx]) {
            score--;
        }
        v[idx] = 0;
    }
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    for (int i = 0; i < 10; i++) {
        cin >> answer[i];
    }
    f(0, 0);
    cout << res << '\n';
}

// 5지선다 문제 10개에서 3개 이상 연속된 답안을 내지 않고 5점 이상 맞는 경우의 수 구하기

// 브루트포스로 모두 확인할 수 있음