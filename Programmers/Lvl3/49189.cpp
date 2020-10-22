// 가장 먼 노드
// https://programmers.co.kr/learn/courses/30/lessons/49189

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int max = 0;
    queue<int> order;
    queue<int> dist;
    vector<bool> visit(n + 1);
    
    order.push(1);
    dist.push(0);
    while(!order.empty()){
        int o = order.front();
        int d = dist.front();
        order.pop();
        dist.pop();
        if (visit[o])
            continue;
        visit[o] = true;
        if (d > max){
            max = d;
            answer = 0;
        }
        if (max == d)
            answer++;
        
        for (int i = 0; i < edge.size(); i++){
            if (edge[i][0] == o && !visit[edge[i][1]]){
                order.push(edge[i][1]);
                dist.push(d + 1);
            }            
            if (edge[i][1] == o && !visit[edge[i][0]]){
                order.push(edge[i][0]);
                dist.push(d + 1);
            }
        }
    }
    
    return answer;
}

// BFS 문제