// 배달
// https://programmers.co.kr/learn/courses/30/lessons/12978

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<vector<int>> map(N + 1, vector<int>(N + 1));
    vector<int> dist(N + 1, -1);
    for (vector<int> v : road){
        if (map[v[0]][v[1]] == 0 || map[v[0]][v[1]] > v[2]){
            map[v[0]][v[1]] = v[2];
            map[v[1]][v[0]] = v[2];
        }
    }
    priority_queue<int> pq;
    pq.push(1);
    dist[1] = 0;
    while(!pq.empty()){
        int cur = pq.top();
        pq.pop();
        for (int i = 1; i <= N; i++){
            if (map[cur][i] != 0){
                if (dist[i] == -1 || dist[i] > map[cur][i] + dist[cur]){
                    dist[i] = map[cur][i] + dist[cur];
                    pq.push(i);
                }
            }
        }
    }
    for (int i : dist)
        if (i <= K)
            answer++;
    answer--;
    return answer;
}

// 마을 간 거리가 주어질 때, 1번 마을에서 K시간 안에 배달할 수 있는 마을의 수 구하기
// 양방향 그래프에서의 다익스트라 문제 - 인접행렬과 우선순위 큐 활용
// 두 마을 간 길이 여러 개가 있을 수 있으나, 어차피 최소 거리 구하는 거니까 가장 적은 것만 저장하기