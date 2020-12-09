// Day 8: Dictionaries and Maps
// https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    map<string, int> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        string s; int p;
        cin >> s >> p;
        m[s] = p;
    } 
    string name;
    while(cin >> name){
        if (m.find(name) == m.end())
            cout << "Not found\n";
        else 
            cout << name << "=" << m[name] << '\n';
    }
    return 0;
}

// n줄의 전화번호부와 *임의의 줄*의 검색이 주어졌을 때 결과 출력하기
// map 사용 연습