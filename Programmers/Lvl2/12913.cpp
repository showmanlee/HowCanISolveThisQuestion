// 땅따먹기
// https://programmers.co.kr/learn/courses/30/lessons/12913

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    vector<vector<int>> dp(land.size(), vector<int>(4));
    dp.assign(land.begin(), land.end());
    for (int i = 1; i < land.size(); i++){
        dp[i][0] += max(dp[i-1][1], max(dp[i-1][2], dp[i-1][3]));
        dp[i][1] += max(dp[i-1][0], max(dp[i-1][2], dp[i-1][3]));
        dp[i][2] += max(dp[i-1][1], max(dp[i-1][0], dp[i-1][3]));
        dp[i][3] += max(dp[i-1][1], max(dp[i-1][2], dp[i-1][0]));
    }
    answer = max(dp[land.size() - 1][0], max(dp[land.size() - 1][1], max(dp[land.size() - 1][2], dp[land.size() - 1][3])));
    return answer;
}

// 폭이 4인 배열을 내려오면서 연속으로 같은 줄 칸을 밟지 않고 먹을 수 있는 최대 점수는?
// 결국 이것도 max를 활용한 DP
// vector값 복사해서 쓸 때는 assign(begin, end)를 사용하자