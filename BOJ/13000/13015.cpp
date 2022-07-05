// 별 찍기 - 23
// https://www.acmicpc.net/problem/13015

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int r = 1; r <= n * 2 - 1; r++) {
        int t = r <= n ? n - r : r - n;
        int u = r <= n ? r - 1 : n - (r - n) - 1;
        for (int i = 0; i < u; i++) {
            cout << ' ';
        }
        if (r == 1 || r == n * 2 - 1) {
            for (int i = 0; i < n; i++) {
                cout << '*';
            }
        } else {
            cout << '*';
            for (int i = 0; i < n - 2; i++) {
                cout << ' ';
            }
            cout << '*';
        }
        for (int i = 0; i < t * 2 - 1; i++) {
            cout << ' ';
        }
        if (r == 1 || r == n * 2 - 1) {
            for (int i = 0; i < n; i++) {
                cout << '*';
            }
        } else {
            if (r != n) {
                cout << '*';
            }
            for (int i = 0; i < n - 2; i++) {
                cout << ' ';
            }
            cout << '*';
        }
        cout << '\n';
    }
}

// 주어진 모양으로 별 찍기

// 실버 이상이 되면 여러 가지 생각해야 하는 조건들이 많아진다 - 그래도 결국은 조건문 반복문 범위 안에 있는 문제