// 게임 맵 최단거리
// https://programmers.co.kr/learn/courses/30/lessons/1844

#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int solution(vector<vector<int>> maps)
{
    int answer = -1;
    int n = maps.size(), m = maps[0].size();
    vector<vector<int>> visit(n, vector<int>(m, -1));
    queue<pr> q;
    q.push({0, 0});
    visit[0][0] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == n - 1 && y == m - 1){
            answer = visit[x][y];
            break;
        }
        for (int i = 0; i < 4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 0 || yy < 0 || xx >= n || yy >= m || visit[xx][yy] != -1)
                continue;
            if (maps[xx][yy] == 1){
                visit[xx][yy] = visit[x][y] + 1;
                q.push({xx, yy});
            }
        }
    }
    return answer;
}

// n*m 맵 좌측 상단에서 우측 하단까지 이동할 수 있는가? 있다면 최소 시간은?
// 평범한 2차원 bfs 최단거리 문제 - 이제는 본능이 되어버린 bfs