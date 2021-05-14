// 합승 택시 요금(2021 카카오)
// https://programmers.co.kr/learn/courses/30/lessons/72413

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 98765432;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, 98765432));
    for (vector<int> v : fares){
        dist[v[0]][v[1]] = v[2];
        dist[v[1]][v[0]] = v[2];
    }
    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    for (int i = 1; i <= n; i++)
        answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
    return answer;
}

// 여러 개의 지점과 지점간 택시 요금이 주어지고, 출발지에서 목적지가 다른 두 사람이 합승하여 택시를 탈 수 있을 때, 두 사람이 각자의 목적지까지 이동하는데 드는 최소 비용은?

// a와 b 각자가 이동하는데 드는 최단거리를 구하면서도, 초반에 합승해서 가는게 저렴하다면 그것까지 고려해야 하는 문제
// 사실 지점 수가 200까지니 플로이드를 돌릴 수 있음
// 플로이드로 모든 경우의 최단 경로를 구했으니, 이 문제의 답을 (출발지-합승종료 + 합승종료-a + 합승종료-b)로 일반화할 수 있음 - 플로이드의 기본 원리도 저러하니
// 따라서 '합승종료' 지점이 될 수 있는 지점들을 모두 순회하며 저 값이 최소가 되는 값을 찾으면, 그것이 답이 됨 - s == i면 합승을 하지 않아도 된다는 것, s == a or s == b인 경우 끝까지 합승한 후 나머지 인원이 다른 택시를 타면 된다는 것