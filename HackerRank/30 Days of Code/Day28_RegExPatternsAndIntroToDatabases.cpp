// Day 28: RegEx, Patterns, and Intro to Databases
// https://www.hackerrank.com/challenges/30-regex-patterns/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int main()
{
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    vector<string> res;
    
    for (int N_itr = 0; N_itr < N; N_itr++) {
        string firstName, emailID;
        cin >> firstName >> emailID;
        if (regex_match(emailID, regex("(.*)@gmail.com")))
            res.push_back(firstName);
    }
    sort(res.begin(), res.end());
    for (string s : res)
        cout << s << '\n';
    return 0;
}


// 정규 표현식 또는 split을 통한 데이터 추출
// gmail.com 이메일을 가지고 있는 사람의 이름을 오름차순으로 표시
// C++에도 정규표현식 라이브러리가 있음 - <regex>
// regex로 객체를 만들고 regex_match로 맞는지 여부 확인
// 긴 문장에 사용하지 않도록 주의 - regex_match는 재귀함수