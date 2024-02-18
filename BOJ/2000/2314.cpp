// 이세계 게임
// https://www.acmicpc.net/problem/2314

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int s = 0, d = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int p = i * 4 + j;
            char c;
            cin >> c;
            s |= (c == 'L' ? 1 : 0) << p;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int p = i * 4 + j;
            char c;
            cin >> c;
            d |= (c == 'L' ? 1 : 0) << p;
        }
    }
    vector<int> v(65537, -1);
    queue<pr> q;
    q.push({s, 0});
    v[s] = 0;
    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (cur == d) {
            cout << cnt << '\n';
            break;
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int x = i;
                int y = j;
                for (int t = 0; t < 4; t++) {
                    int xx = x + dx[t];
                    int yy = y + dy[t];
                    if (xx < 0 || yy < 0 || xx >= 4 || yy >= 4) {
                        continue;
                    }
                    int xy = x * 4 + y;
                    int xxy = xx * 4 + yy;
                    int curr = cur;
                    if ((curr >> xy) % 2 != (curr >> xxy) % 2) {
                        if ((curr >> xy) % 2 == 0) {
                            curr |= 1 << xy;
                            curr &= ~(1 << xxy);
                        } else {
				            curr &= ~(1 << xy);
                            curr |= 1 << xxy;
                        }
                        if (v[curr] == -1) {
                            v[curr] = cnt + 1;
                            q.push({curr, cnt + 1});
                        }
                    }
                }
            }
        }
    }
}

// P 또는 L이 적힌 4x4 보드에서 상하좌우로 맞닿은 두 칸을 서로 뒤집을 수 있을 때, 주어진 보드를 또다른 보드의 형태로 바꾸는데 필요한 최소 이동 수 구하기

// 비트마스킹 + bfs - 4x4 보드를 16비트 정수형으로 변환하고, 이를 이용해 bfs를 돌립시다