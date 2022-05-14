// Sentences
// https://www.acmicpc.net/problem/6970

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   string s;
   getline(cin, s);
   int tt = stoi(s);
   for (int t = 0; t < tt; t++) {
      getline(cin, s);
      int a = stoi(s);
      getline(cin, s);
      int b = stoi(s);
      getline(cin, s);
      int c = stoi(s);
      vector<string> sub, verb, obj;
      for (int i = 0; i < a; i++) {
         string ss;
         getline(cin, ss);
         sub.push_back(ss);
      }
      for (int i = 0; i < b; i++) {
         string ss;
         getline(cin, ss);
         verb.push_back(ss);
      }
      for (int i = 0; i < c; i++) {
         string ss;
         getline(cin, ss);
         obj.push_back(ss);
      }
      for (string aa : sub) {
         for (string bb : verb) {
            for (string cc : obj) {
               cout << aa << ' ' << bb << ' ' << cc << ".\n";
            }
         }
      }
      cout << '\n';
   }
}

// 주어, 동사, 목적어가 한 세트씩 알파벳 순서로 주어질 때, 만들 수 있는 모든 문장을 알파벳 순서로 호출하기

// 주어/동사/목적어 순 순서쌍을 각 요소마다 알파벳 순서로 출력한다
// 테케 사이에는 공백 넣고, 각 요소 안에 공백 있으니 getline으로 받아주고