// Поп-ит
// https://www.acmicpc.net/problem/30585

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int v[2] = {0, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            v[c - '0']++;
        }
    }
    cout << min(v[0], v[1]) << '\n';
}

// n*m 보드에 0과 1이 있을 때 모든 칸을 같은 숫자로 채우기 위해 바꿔야 하는 칸의 최소 수 구하기

// 개수를 세고 적은 수 출력하기