// 실패율(2019 카카오)
// https://programmers.co.kr/learn/courses/30/lessons/42889

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<double> prob(N + 1);
    double deadsum = 0;
    for (int i = 0; i < stages.size(); i++)
        prob[stages[i] - 1] += 1; 
    for (int i = 0; i < prob.size() - 1; i++){
        double p = prob[i];
        prob[i] /= (double)(stages.size() - deadsum);
        deadsum += p;
        answer.push_back(i + 1);
    }
    for (int i = 0; i < answer.size(); i++)
        for (int j = i; j < answer.size(); j++){
            if (prob[answer[i] - 1] < prob[answer[j] - 1]){
                int p = answer[i];
                answer[i] = answer[j];
                answer[j] = p;
            }
            else if (prob[answer[i] - 1] == prob[answer[j] - 1]){
                if (answer[i] > answer[j]){
                int p = answer[i];
                answer[i] = answer[j];
                answer[j] = p;
                }
            }
        }
    return answer;
}

// N개의 스테이지로 구성되어있는 게임, 막힌 스테이지는 stages에 나열(N+1은 완료)