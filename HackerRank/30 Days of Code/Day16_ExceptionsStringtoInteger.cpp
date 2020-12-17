// Day 16: Exceptions - String to Integer
// https://www.hackerrank.com/challenges/30-exceptions-string-to-integer/problem

#include <iostream>
#include <string>

using namespace std;

int main(){
    string S;
    cin >> S;
    try{
        int i = stoi(S);
        cout << i << '\n';
    }
    catch(...){
        cout << "Bad String" << '\n';
    }
    return 0;
}

// 예외 처리로 숫자만 있는 문자열 구분하기
// try... catch(int e)
// catch(...)로 모든 오류 받기