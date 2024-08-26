// Arithmetic Sequences
// https://www.acmicpc.net/problem/15130

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<int> v(10);
    int a = 0, b = 0, d = 0, idx = 0;
    for (int i = 0; i < 10; i++) {
        cin >> v[i];
        if (v[i] != 0) {
            if (a == 0) {
                a = v[i];
                idx = i;
            } else {
                b = v[i];
            }
        }
        if (a != 0 && b == 0) {
            d++;
        }
    }
    int x = b - a;
    if (x % d != 0) {
        cout << -1 << '\n';
    } else {
        int t = x / d;
        int p = a - (idx * t);
        for (int i = 0; i < 10; i++) {
            v[i] = p + (i * t);
            cout << v[i] << ' ';
        }
        cout << '\n';
    }
}

// 등차수열에서 2칸만 채워져 있을 때, 모든 칸을 정수로 채운 결과 출력하기

// 두 칸의 거리를 보고 차/거리가 나누어떨어지면 등차 구해서 계산하기