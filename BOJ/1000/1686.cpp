// 복날
// https://www.acmicpc.net/problem/1686

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<double, double> coord;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    double v, m;
    cin >> v >> m;
    vector<coord> board;
    for (int i = 0; i < 2; i++) {
        double a, b;
        cin >> a >> b;
        board.push_back({a, b});
    }
    double d;
    while(cin >> d) {
        double e;
        cin >> e;
        board.push_back({d, e});
    }
    int n = board.size();
    double limit = v * m * 60;
    vector<int> visit(n, -1);
    visit[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int idx = q.front();
        q.pop();
        if (idx == 1) {
            break;
        }
        for (int i = 0; i < n; i++) {
            if (i != idx && visit[i] == -1) {
                double x = abs(board[idx].first - board[i].first);
                double y = abs(board[idx].second - board[i].second);
                double d = sqrt(x * x + y * y);
                if (d < limit) {
                    visit[i] = visit[idx] + 1;
                    q.push(i);
                }
            }
        }
    }
    if (visit[1] == -1) {
        cout << "No.\n";
    } else {
        cout << "Yes, visiting " << (visit[1] - 1) << " other holes.\n";
    }
}

// 초속 v m/s로 움직일 수 있는 닭이 출발 좌표에서 도착 좌표로 이동하는데, 벙커에 도달하지 않고 m분 이상 있으면 잡힌다고 할 때, 출발점에서 도착점으로 이동 가능 여부와 최소 벙커 경유 개수 출력하기

// 좌표가 소수로 주어질 수 있고 이동 거리 계산을 해야 하지만, 결국 들르는 벙커 개수만 따지면 되므로 bfs로 구할 수 있다
// 좌표 개수는 1000개이므로 한 점에 도달할 때마다 거리를 계산해줘도 됨 - 자기 자신과 이미 들른 좌표 제외하고
// 최대 이동 거리는 v * m * 60 - v는 초속, m은 분이니까 60을 곱하기
// 최대 이동 거리 미만이어야 이동 가능함에 주의