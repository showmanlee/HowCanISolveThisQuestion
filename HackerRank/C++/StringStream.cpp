// StringStream
// https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    stringstream ss(str);
    vector<int> res;
    char c;
    int tmp;
    while (ss >> tmp) {
        res.push_back(tmp);
        ss >> c;
    }
    return res;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}

// #include <sstream> 안의 stringstream = c++에서 split을 사용할 수 있는 방법
// 이걸로 문자열 관련 문제들도 c++로 풀 수 있다
// streamstring ss(str) - string str을 이용한 스트림을 만듬
// ss >> a >> b >> c - cin 처럼 ss에서 데이터를 받는다(str의 끝에 다다랐다면 NULL 반환 - while문으로 처리 가능)
// ss << "a" - str에 해당 데이터 추가
// ss.str() = 문자열 반환
// ss.str(strr) = 문자열 재설정