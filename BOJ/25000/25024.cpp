// 시간과 날짜
// https://www.acmicpc.net/problem/25024

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   int tt;
   cin >> tt;
   for (int t = 0; t < tt; t++) {
      int a, b;
      cin >> a >> b;
      cout << (a <= 23 && b <= 59 ? "Yes " : "No ");
      if (a == 1 || a == 3 || a == 5 || a == 7 || a == 8 || a == 10 || a == 12) {
         if (b >= 1 && b <= 31) {
            cout << "Yes";
         } else {
            cout << "No";
         }
      }
      else if (a == 4 || a == 6 || a == 9 || a == 11) {
         if (b >= 1 && b <= 30) {
            cout << "Yes";
         } else {
            cout << "No";
         }
      } else if (a == 2) {
         if (b >= 1 && b <= 29) {
            cout << "Yes";
         } else {
            cout << "No";
         }
      } else {
         cout << "No";
      }
      cout << '\n';
   }
}

// 주어진 두 숫자가 24시간과 날짜로 읽힐 수 있는지 판정하기

// 시간은 0:00~23:59 안에 있는지 체크하기
// 날짜의 경우 월을 보고 1일부터 그 달 끝 범위 안에 있는지 체크하기