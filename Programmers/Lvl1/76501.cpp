// 음양 더하기
// https://programmers.co.kr/learn/courses/30/lessons/76501

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    int n = signs.size();
    for (int i = 0; i < n; i++){
        if (!signs[i])
            absolutes[i] *= -1;
        answer += absolutes[i];
    }
    return answer;
}

// 절댓값들과 각 절댓값에 붙는 부호가 주어질 때, 해당 수들의 합 구하기
// 양수라면 절댓값을, 음수라면 절댓값 * -1을 계속 더해주기