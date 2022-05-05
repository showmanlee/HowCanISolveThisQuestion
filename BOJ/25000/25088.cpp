// Punched Cards
// https://www.acmicpc.net/problem/25088

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   int tt;
   cin >> tt;
   for (int t = 1; t <= tt; t++) {
      int x, y;
      cin >> x >> y;
      cout << "Case #" << t << ":\n";
      for (int i = 0; i < x; i++) {
         for (int j = 0; j < y; j++) {
            if (i == 0 && j == 0) {
               cout << "..";
            } else {
               cout << "+-";
               if (j == y - 1) {
                  cout << "+\n";
               }
            }
         }
         for (int j = 0; j < y; j++) {
            if (i == 0 && j == 0) {
               cout << "..";
            } else {
               cout << "|.";
               if (j == y - 1) {
                  cout << "|\n";
               }
            }
         }
      }
      for (int j = 0; j < y; j++) {
         cout << "+-";
         if (j == y - 1) {
            cout << "+\n";
         }
      }
   }
}

// 좌측 상단이 깎인 x*y 사이즈의 천공카드 출력하기

// 시키는 대로 출력하기