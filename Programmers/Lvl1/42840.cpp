// 모의고사
// https://programmers.co.kr/learn/courses/30/lessons/42840

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int p1 = 0, p2 = 0, p3 = 0;
    int a1[5] = {1,2,3,4,5};
    int a2[8] = {2,1,2,3,2,4,2,5};
    int a3[10] = {3,3,1,1,2,2,4,4,5,5};
    for(int i = 0; i < answers.size(); i++){
        if (answers[i] == a1[i % 5])
            p1++;
        if (answers[i] == a2[i % 8])
            p2++;
        if (answers[i] == a3[i % 10])
            p3++;
    }
    if (p1 == p2 && p2 == p3){
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);        
    }
    else if (p1 == p2 && p2 > p3){
        answer.push_back(1);
        answer.push_back(2);
    }
    else if (p3 == p2 && p2 > p1){
        answer.push_back(2);
        answer.push_back(3);
    }
    else if (p1 == p3 && p1 > p2){
        answer.push_back(1);
        answer.push_back(3);
    }
    else if (p1 > p2 && p1 > p3)
        answer.push_back(1);
    else if (p2 > p1 && p2 > p3)
        answer.push_back(2);
    else if (p3 > p1 && p3 > p2)
        answer.push_back(3);
    return answer;
}

// 완전탐색의 기본?