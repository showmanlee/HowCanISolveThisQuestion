// 최애의 팀원
// https://www.acmicpc.net/problem/29813

#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<string, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    queue<pr> q;
    for (int i = 0; i < n; i++) {
        string s;
        int p;
        cin >> s >> p;
        q.push({s, p});
    }
    while (q.size() > 1) {
        int t = q.front().second;
        q.pop();
        for (int i = 0; i < t - 1; i++) {
            pr pp = q.front();
            q.pop();
            q.push(pp);
        }
        q.pop();
    }
    cout << q.front().first << '\n';
}

// 각각의 이름과 수를 가장 앞에 있는 사람이 그 뒤에 있는 사람들을 수만큼 뒤로 옮기면서 마지막으로 앞에 있는 사람을 데려갈 때, 마지막 남은 1명의 이름 구하기

// 실제로 돌려보기