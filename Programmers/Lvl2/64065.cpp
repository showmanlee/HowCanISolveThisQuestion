// 튜플(2019 카카오 인턴십)
// https://programmers.co.kr/learn/courses/30/lessons/64065

#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> tuples;
    int index = 0;
    for (int i = 0; i < s.length(); i++){
        switch(s[i]){
            case '{':
            case ',':
                s[i] = ' ';
                break;
            case '}':
                s[i] = '|';
                break;
        }
        if (s[i] == '|' && i - index > 2){
            tuples.push_back(s.substr(index, i - index).substr(2) + " ");
            index = i + 1;
        }
    }
    
    for (int i = 0; i < tuples.size(); i++){
        for (int j = i; j < tuples.size(); j++){
            if (tuples[i].length() > tuples[j].length()){
                string p = tuples[i];
                tuples[i] = tuples[j];
                tuples[j] = p;
            }
        }
    }
    
    for (int i = 0; i < tuples.size(); i++){
        int k = 0;
        for (int j = 0; j < tuples[i].length(); j++)
            if (tuples[i][j] == ' ') {
                int n = atoi(tuples[i].substr(k, j - k).c_str());
                k = j + 1;
                if (find(answer.begin(), answer.end(), n) == answer.end()){
                    answer.push_back(n);
                    break;
                }
            }
    }
    return answer;
}

// 순서가 존재하는 튜플.
// 튜플은 { }들을 이용해 1개에서 x개까지 원소가 채워지는 순서를 표현할 수 있다.
// 단, 이 경우 { }안의 순서는 무시한다.
// answer 길이는 최대 500, 숫자는 1~100000