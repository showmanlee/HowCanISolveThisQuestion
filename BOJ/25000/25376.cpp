// 이상한 스위치
// https://www.acmicpc.net/problem/25376

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int s = 0;
    int maxx = 1 << (n + 1);
    int d = maxx - 2;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        if (p) {
            s |= 1 << i;
        } else {
            s &= ~(1 << i);
        }
    }
    vector<vector<int>> conn(n + 1);
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        for (int j = 0; j < t; j++) {
            int p;
            cin >> p;
            conn[i].push_back(p);
        }
    }
    vector<int> visit(maxx, -1);
    visit[s] = 0;
    queue<pr> q;
    q.push({s, 0});
    while(!q.empty()) {
        int p = q.front().first;
        int dist = q.front().second;
        q.pop();
        if (p == d) {
            break;
        }
        for (int i = 1; i <= n; i++) {
            int pp = p;
            int key = (p >> i) % 2;
            if (!key) {
                pp |= 1 << i;
                for (int j : conn[i]) {
                    if ((pp >> j) % 2) {
                        pp &= ~(1 << j);
                    } else {
                        pp |= 1 << j;
                    }
                }
                if (visit[pp] == -1) {
                    visit[pp] = dist + 1;
                    q.push({pp, dist + 1});
                }
            }
        }
    }
    cout << visit[d] << '\n';
}

// n개의 스위치들이 주어진 대로 서로 연결된 상황에서 꺼져 있는 스위치만 직접 켤 수 있고, 직접 켠 스위치에 의해 연결된 스위치의 상태가 반전될 때, 모든 스위치를 켤 수 있는지 여부와 그러기 위한 최소 횟수 구하기

// 비트마스킹을 이용한 bfs 문제 - 비트마스킹 표기법은 11723 참고
// 처음에 모두 빈 상태에서 출발해, 꺼져있는 스위치 별로 해당 스위치와 그와 연결된 스위치들을 켠 뒤, 그 경우를 방문한 적이 없다면 큐에 삽입
// 그렇게 bfs를 계속 돌다가 모두 켜져 있는 상태(111)에 도달하면 탐색을 멈춘다 - 최종적으로 못 닿아도 멈추는 거고
// 여기서는 스위치 인덱스가 1부터 시작함을 감안, 비트마스킹을 1비트 더 쓰고 최종 상태를 1110으로 설정해둔 상황