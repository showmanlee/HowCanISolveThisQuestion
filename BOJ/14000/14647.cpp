// 준오는 조류혐오야!!
// https://www.acmicpc.net/problem/14647

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int p;
            cin >> p;
            while (p > 0) {
                if (p % 10 == 9) {
                    v[i][j]++;
                    res++;
                }
                p /= 10;
            }
        }
    }
    int xxc = 0, yyc = 0;
    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = 0; j < m; j++) {
            c += v[i][j];
        }
        if (c > xxc) {
            xxc = c;
        }
    }
    for (int j = 0; j < m; j++) {
        int c = 0;
        for (int i = 0; i < n; i++) {
            c += v[i][j];
        }
        if (c > yyc) {
            yyc = c;
        }
    }
    cout << (res - max(xxc, yyc)) << '\n';
}

// 수들이 적힌 n*m 보드에서 9가 가장 많이 등장하는 행 또는 열을 지울 때, 남은 9의 개수 출력하기

// 출력하면 됩니다 - 각 칸의 9 위치를 세주고, 9가 가장 많이 등장하는 행/열을 체크하고, 그 행/열 중 가장 9가 많은 줄을 찾아 계산