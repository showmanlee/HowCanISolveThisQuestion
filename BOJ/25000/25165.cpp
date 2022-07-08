// 영리한 아리의 포탈 타기
// https://www.acmicpc.net/problem/25165

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m, a, d, dx, dy;
    cin >> n >> m >> a >> d >> dx >> dy;
    bool res = true;
    int pos = a;
    int dir = d;
    for (int i = 1; i <= n; i++) {
        if (i == n && pos == m) {
            break;
        }
        while(true) {
            if (i == dx && pos == dy) {
                res = false;
                break;
            }
            pos += (dir ? 1 : -1);
            if (pos == 0) {
                pos = 1;
            } else if (pos == m + 1) {
                pos = m;
            }
            if (i == dx && pos == dy) {
                res = false;
                break;
            }
            if (pos == 1 || pos == m) {
                dir = (dir ? 0 : 1);
                break;
            }
        }
        if (!res) {
            break;
        }
    }
    cout << (res ? "YES!" : "NO...") << '\n';
}

// n*m 보드를 첫줄의 출발점에서 우측 하단까지 s자로 내려올 때, 특정 칸을 밟을 수 있는가?

// s자로 내려오는 메커니즘을 만든다 - 그거 관련해서 생각해줘야 하는 부분들이 몇 있긴 하다
// 마지막에 도착하는 방식은 마지막줄로 내려오면서 끝나거나 마지막줄 순회하다 끝나거나