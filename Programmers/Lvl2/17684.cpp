// 압축(2018 카카오)
// https://programmers.co.kr/learn/courses/30/lessons/17684

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> dict;
    for (int i = 0; i < 26; i++){
        string c;
        c.push_back('A' + i);
        dict.push_back(c);
    }
    while (msg.size() != 0){
        for (int i = dict.size() - 1; i >= 0; i--){                
            if (msg.substr(0, dict[i].size()) == dict[i]){
                if (msg.size() > dict[i].size())
                    dict.push_back(msg.substr(0, dict[i].size() + 1));
                msg.erase(0, dict[i].size());
                answer.push_back(i + 1);
                break;
            }
        }
    }
    return answer;
}