// 1, 2, 3 더하기 2
// https://www.acmicpc.net/problem/12101

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int order = 0;
int v[12];

void func(int sum, int cnt) {
    if (order >= k) {
        return;
    }
    if (sum == n) {
        order++;
        if (order == k) {
            for (int i = 0; i < cnt; i++) {
                cout << v[i];
                if (i < cnt - 1) {
                    cout << '+';
                }
            }
            cout << '\n';
            return;
        }
    } else if (sum > n) {
        return;
    }
    for (int i = 1; i <= 3; i++) {
        v[cnt] = i;
        if (sum + i <= n) {
            func(sum + i, cnt + 1);
        }
        v[cnt] = 0;
        if (order >= k) {
            return;
        }
    }
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    cin >> n >> k;
    func(0, 0);
    if (order < k) {
        cout << -1 << '\n';
    }
}

// 1, 2, 3의 합으로 n을 만드는 경우 중 사전 순으로 정렬했을 때 k번째 경우 출력하기

// dfs로 하나씩 확인해본다