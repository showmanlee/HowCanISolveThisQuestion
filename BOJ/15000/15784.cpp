// 질투진서
// https://www.acmicpc.net/problem/15784

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }
    bool res = false;
    for (int i = 1; i <= n; i++) {
        if (v[a][b] < v[a][i] || v[a][b] < v[i][b]) {
            res = true;
        }
    }
    cout << (res ? "ANGRY" : "HAPPY") << '\n';
}

// n*n 정수 보드가 주어질 때, (a, b)칸과 같은 행/열에 있는 수 중 (a, b)보다 큰 수가 있는지 확인하기

// 2차원 배열을 받아서 확인