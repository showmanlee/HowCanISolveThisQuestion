// 카드
// https://www.acmicpc.net/problem/1835

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    deque<int> dq;
    dq.push_back(n);
    for (int i = n - 1; i > 0; i--) {
        dq.push_front(i);
        for (int j = 0; j < i; j++) {
            int p = dq.back();
            dq.pop_back();
            dq.push_front(p);
        }
    }
    while (!dq.empty()) {
        cout << dq.front() << ' ';
        dq.pop_front();
    }
}

// 문제에 주어진 상황대로 카드를 버릴 수 있도록 1~n 카드를 쌓는 순서 구하기

// 역순대로 만들기