// 소트인사이드
// https://www.acmicpc.net/problem/1427

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
    string s;
    cin >> s;
    sort(s.begin(), s.end(), greater<char>());
    cout << s << endl;
}

// C++에서 이런 것도 돼
// C++에서 string은 vector의 일종