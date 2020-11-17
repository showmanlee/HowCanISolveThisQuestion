// 섬 연결하기
// https://programmers.co.kr/learn/courses/30/lessons/42861

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> cycle(n);
    for (int i = 0; i < n; i++)
        cycle[i] = i;
    sort(costs.begin(), costs.end(), compare);
    for (vector<int>& v : costs){
        if (v[0] > v[1])
            swap(v[0], v[1]);
        if (cycle[v[0]] != cycle[v[1]]){
            int p = cycle[v[1]];
            cycle[v[1]] = cycle[v[0]];
            for (int& i : cycle){
                if (i == p)
                    i = cycle[v[0]];
            }
            answer += v[2];
        }
    }
    return answer;
}

// 크루스칼 알고리즘 - 최소 신장 트리(가중치가 가장 적은 간선으로 이은 트리) 만들기
// 주어진 간선을 가중치 순서대로 정렬한 뒤, 두 노드가 연결된 상태가 아니라면 해당 간선으로 연결한다
// 다만 '두 노드가 연결된 상태'를 bool 배열로 나타내면 두 개 이상의 섬으로 고립될 수 있음 - Union-Find 알고리즘 접목 필욘
// 0. 주어진 간선을 가중치 순서대로 정렬한다.
// 1. 노드 별 연결 여부를 나타내는 배열을 만들고, 초기값은 노드 번호와 같은 번호로 설정한다.
// 2. 노드가 연결되면 해당 배열의 두 노드의 값을 더 작은 값으로 만들어주고, 두 노드와 이미 연결된 노드들의 값도 바꿔준다.
// 3. 만약 두 노드가 이미 연결된 상태라면 무시한다.
// 4. 그러다가 모든 노드가 연결되면 탈출