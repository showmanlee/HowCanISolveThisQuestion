// 주식 가격
// https://programmers.co.kr/learn/courses/30/lessons/42584

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for (int i = 0; i < prices.size(); i++){
        int t = 0;
        for (int j = i + 1; j < prices.size(); j++){
            t++;
            if (prices[i] > prices[j])
                break;
        }
        answer.push_back(t);
    }
    return answer;
}