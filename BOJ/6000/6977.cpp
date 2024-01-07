// Pattern Generator
// https://www.acmicpc.net/problem/6977

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int v[31];

void func(int p, int c) {
    if (p == n) {
        if (c == 0) {
            for (int i = 0; i < n; i++) {
                cout << v[i];
            }
            cout << '\n';
        }
        return;
    }
    if (c == 0) {
        func(p + 1, c);
    } else {
        v[p] = 1;
        func(p + 1, c - 1);
        v[p] = 0;
        func(p + 1, c);
    }
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            v[i] = 0;
        }
        cout << "The bit patterns are\n";
        func(0, k);
        cout << '\n';
    }
}

// n개의 비트 중 k개가 1인 모든 비트쌍 구하기

// 백트래킹으로 구해봅니다