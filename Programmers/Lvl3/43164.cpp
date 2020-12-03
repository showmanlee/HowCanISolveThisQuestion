// 여행경로
// https://programmers.co.kr/learn/courses/30/lessons/43164

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<string, string> pr;
vector<bool> used;

bool dfs(vector<vector<string>>& tickets, vector<string>& answer, string begin, int idx){
    answer[idx] = begin;
    if (idx == tickets.size())
        return true;
    for (int i = 0; i < tickets.size(); i++){
        if (tickets[i][0] == begin && !used[i]){
            used[i] = true;
            int res = dfs(tickets, answer, tickets[i][1], idx + 1);
            if (!res)
                used[i] = false;
            else
                return true;
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer(tickets.size() + 1);
    used.resize(tickets.size());
    sort(tickets.begin(), tickets.end(), [](vector<string> a, vector<string> b){
        if (a[0] == b[0])
            return a[1] < b[1];
        else
            return a[0] < b[0];
    });
    dfs(tickets, answer, "ICN", 0);
    return answer;
}

// ICN에서 출발하여 주어진 티켓을 모두 써서 만들 수 있는 여행 경로 중 사전 순서가 가장 앞서는 경로 출력
// 단방향 그래프를 이용한 DFS 문제
// 사전 순서가 앞서도록 하는 건 사전 순서대로 배열을 정렬해서 해결 가능
// 문제는 티켓을 모두 써서 경로를 만들게 하는 것인데
// dfs 함수 자체를 bool을 반환하게 만들고, 규정된 인덱스에 다다르면(= 모든 티켓을 쓰면) true를 반환, 그렇지 않으면 false 반환하기
// dfs 함수를 부르는 쪽에서 dfs의 반환값을 체크하고, 만약 true를 받았으면 true를 같이 반환하여 함수를 아예 끝내버리고, 그렇지 않으면 used(visit) 배열 체크한 것을 해제하여 다른 경로에 활용할 수 있게 하기