// 순위
// https://programmers.co.kr/learn/courses/30/lessons/49191

#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> rel(n + 1, vector<int>(n + 1));
    for (vector<int> v : results){
        rel[v[0]][v[1]] = 1;
        rel[v[1]][v[0]] = -1;
    }
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (rel[i][j] == 0){
                    if (rel[i][k] == rel[k][j] && rel[i][k] != 0)
						rel[i][j] = rel[i][k];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++){
        int cnt = 0;
        for (int j = 1; j <= n; j++){
            if (rel[i][j] != 0)
                cnt++;
        }
        if (cnt == n - 1)
            answer++;
    }
    return answer;
}

// 풀리그 방식의 대회에서 일부 경기의 결과가 주어지고, 실력이 좋은 사람은 낮은 사람을 언제나 이김이 보장될 때, 정확히 순위를 매길 수 있는 사람의 수는?

// 언제나 이김이 보장된다는 것은 곧 선수간의 전후관계가 주어진다는 것
// 모든 노드들의 전후관계를 확인하기 위해서도 플로이드 알고리즘을 사용할 수 있음
// 결과들을 2차원 배열로 다시 표현 - a가 b를 이겼다면 [a][b] = -1, [b][a] = 1
// 이 배열에 플로이드 알고리즘을 도입, [i][k]와 [k][j]에 같은 결과가 나타난다면 [i][j]도 같은 결과가 된다

// 강한 사람은 약한 사람을 언제나 이김이 보장되기 때문에, 이 대회는 공동 순위가 나올 수 없다
// 때문에 자신을 제외한 모든 사람들의 결과가 정확히 파악된다면 그 사람의 순위도 알 수 있다
// 즉, 플로이드를 돌린 결과 배열에서 자신을 제외한 모든 사람의 결과관계가 채워졌다면 그 사람의 순위를 알 수 있는 상태라는 것
// 이를 이용해 결과를 구하고 반환하기