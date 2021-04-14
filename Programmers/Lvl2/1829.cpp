// 카카오 프렌즈 컬러링북
// https://programmers.co.kr/learn/courses/30/lessons/1829

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pr;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    vector<vector<bool>> visit(m, vector<bool>(n));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (!visit[i][j] && picture[i][j] != 0){
                number_of_area++;
                queue<pr> q;
                q.push({i, j});
                visit[i][j] = true;
                int size = 0;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    size++;
                    for (int t = 0; t < 4; t++){
                        int xx = x + dx[t];
                        int yy = y + dy[t];
                        if (xx < 0 || yy < 0 || xx >= m || yy >= n)
                            continue;
                        if (!visit[xx][yy] && picture[x][y] == picture[xx][yy]){
                            visit[xx][yy] = true;
                            q.push({xx, yy});
                        }
                    }
                }
                max_size_of_one_area = max(size, max_size_of_one_area);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

// m*n 그림에 몇 개의 영역이 있고, 가장 큰 영역의 크기는 얼마인가?
// bfs 영역탐색 기본 문제