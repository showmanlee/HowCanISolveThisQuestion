// 영어 끝말잇기
// https://programmers.co.kr/learn/courses/30/lessons/12981

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int player = 2, turn = 1;
    string prev = words[0];
    
    // 중복 체크
    for (int i = 1; i < words.size(); i++){
        bool same = false;
        if (words[i-1][words[i-1].length()-1] != words[i][0]){
            answer.push_back(player);
            answer.push_back(turn);
            break;
        }
        for (int j = 0; j < i; j++)
            if (words[j] == words[i]){
                same = true;
                break;
            }
        if (same){
            answer.push_back(player);
            answer.push_back(turn);
            break;
        }
        
        player++;
        if (player > n){
            player = 1;
            turn++;
        }
    }
    if (answer.size() == 0){
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}