// 매직 포션
// https://www.acmicpc.net/problem/12913

#include <iostream>
#include <vector>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pr;
typedef pair<double, pr> prr;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    vector<vector<double>> dist(k + 1, vector<double>(n, 987654321));
    dist[k][0] = 0;
    priority_queue<prr> pq;
    pq.push({ 0, {k, 0} });
    while (!pq.empty()) {
        double len = -pq.top().first;
        int potion = pq.top().second.first;
        int cur = pq.top().second.second;
        pq.pop();
        for (int i = 0; i < n; i++) {
            if (i == cur)
                continue;
            double nlen = len + board[cur][i];
            if (dist[potion][i] > nlen) {
                dist[potion][i] = nlen;
                pq.push({ -nlen, {potion, i} });
            }
            if (potion > 0) {
                nlen = len + (board[cur][i] / 2.0);
                if (dist[potion - 1][i] > nlen) {
                    dist[potion - 1][i] = nlen;
                    pq.push({ -nlen, {potion - 1, i} });
                }
            }
        }
    }
    double res = 987654321;
    for (int i = 0; i <= k; i++)
        res = min(res, dist[i][1]);
    cout << res << '\n';
}

// 마을끼리 모두 연결된 n개의 마을을 이동할 때 매직 포션 하나를 소모하여 절반의 시간으로 두 마을을 이동할 수 있을 때, 주어진 매직 포션를 활용해 0번 마을에서 1번 마을로 이동할 수 있는 최소 시간은?

// 다익스트라 + 벽 부수고 이동하기 - 포션 소모량에 따라 dist 배열을 달리 둬야 함
// 평소처럼 다익스트라를 돌리는데, 포션이 남았다면 포션을 소모하지 않는 과정과 소모하는 과정을 모두 계산하여 큐에 넣어야 함
// 이러한 방식으로 포션 소모량에 따른 최소 이동 거리들을 구할 수 있는데, 여기서 1번 마을로 가는 최소 거리가 답이 됨
// 절반의 시간을 계산할 때 실수형이 나올 수 있기에 dist 배열은 double로 관리하기