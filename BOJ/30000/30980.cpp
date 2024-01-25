// 여중생 파댕이와 공부를
// https://www.acmicpc.net/problem/30980

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<string> v(n * 3);
    for (int i = 0; i < n * 3; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n * 3; i += 3) {
        for (int j = 0; j < m * 8; j += 8) {
            bool one = v[i + 1][j + 6] == '.';
            int a = v[i + 1][j + 1] - '0';
            int b = v[i + 1][j + 3] - '0';
            int c = (one ? (v[i + 1][j + 5] - '0') : (v[i + 1][j + 5] - '0') * 10 + (v[i + 1][j + 6] - '0'));
            if (a + b == c) {
                for (int t = 1; t <= (one ? 5 : 6); t++) {
                    v[i][j + t] = v[i + 2][j + t] = '*';
                }
                v[i + 1][j] = '*';
                if (one) {
                    v[i + 1][j + 6] = '*';
                } else {
                    v[i + 1][j + 7] = '*';
                }
            } else {
                v[i][j + 3] = v[i + 1][j + 2] = v[i + 2][j + 1] = '/';
            }
        }
    }
    for (int i = 0; i < n * 3; i++) {
        cout << v[i] << '\n';
    }
}

// 덧셈 수식이 문제에 나온 형식대로 주어질 때, 문제에서 시키는 대로 동그라미/줄표 그리기

// 문제를 잘 보고 정확한 칸에 문자를 채워넣어보세요