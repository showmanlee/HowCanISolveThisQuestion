// new time
// https://www.acmicpc.net/problem/26876

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;
    int sh = (a[0] - '0') * 10 + (a[1] - '0');
    int sm = (a[3] - '0') * 10 + (a[4] - '0');
    int eh = (b[0] - '0') * 10 + (b[1] - '0');
    int em = (b[3] - '0') * 10 + (b[4] - '0');

    vector<vector<int>> visit(24, vector<int>(60, -1));
    visit[sh][sm] = 0;
    queue<pr> q;
    q.push({sh, sm});
    while(!q.empty()) {
        int h = q.front().first;
        int m = q.front().second;
        q.pop();
        if (h == eh && m == em) {
            cout << visit[h][m] << '\n';
            break;
        }
        int hh, mm;
        hh = (h + 1) % 24;
        mm = m;
        if (visit[hh][mm] == -1) {
            visit[hh][mm] = visit[h][m] + 1;
            q.push({hh, mm});
        }
        mm = (m + 1) % 60;
        hh = (mm == 0 ? (h + 1) % 24 : h);
        if (visit[hh][mm] == -1) {
            visit[hh][mm] = visit[h][m] + 1;
            q.push({hh, mm});
        }
    }
}

// 디지털 시계에서 시/분을 1씩 올릴 수 있는 버튼이 있을 때, 주어진 시각으로 가는데 필요한 최소 버튼 입력 횟수 구하기

// 버튼을 눌러본다 - bfs?