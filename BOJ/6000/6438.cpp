// Reverse Text
// https://www.acmicpc.net/problem/6438

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
   //cin.tie(NULL);
   //ios_base::sync_with_stdio(false);

   string s;
   getline(cin, s);
   int n = stoi(s);
   for (int i = 0; i < n; i++) {
      getline(cin, s);
      reverse(s.begin(), s.end());
      cout << s << '\n';
   }
}

// 주어진 문자열 거꾸로 출력하기

// 하면 되지요 - 공백 있는 문자열만 잘 받아준다면