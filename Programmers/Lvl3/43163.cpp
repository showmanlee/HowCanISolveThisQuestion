// 단어 변환
// https://programmers.co.kr/learn/courses/30/lessons/43163

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<string, int> pr;

int solution(string begin, string target, vector<string> words) {
    queue<pr> q;
    if (find(words.begin(), words.end(), target) == words.end())
        return 0;
    q.push({begin, 0});
    while(!q.empty()){
        string s = q.front().first;
        int n = q.front().second;
        if (s == target)
            return n;
        q.pop();
        for (int i = 0; i < s.length(); i++){
            string ss = s;
            for (char j = 'a'; j <= 'z'; j++){
                ss[i] = j;
                if (ss == s)
                    continue;
                if (find(words.begin(), words.end(), ss) != words.end()){
                    q.push({ss, n + 1});
                }
            }
        }
    }
    return 0;
}

// BFS 문제
// 주어진 문자열을 한 글자씩 바꾼 후 리스트에 있으면 큐에 넣기
// 지금 규모에서는 visit 배열 없어도 풀림