// 숫자 카드놀이
// https://www.acmicpc.net/problem/4564

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   while (true) {
      int n;
      cin >> n;
      if (n == 0) {
         break;
      }
      cout << n << ' ';
      while(n >= 10) {
         string s = to_string(n);
         int p = 1;
         for (char c : s) {
            p *= c - '0';
         }
         cout << p << ' ';
         n = p;
      }
      cout << '\n';
   }
}

// 자연수의 각 자릿수를 모두 곱해 한자릿수가 나올 때까지 반복한 결과 출력하기

// 자연수를 받고, 문자열로 바꾸고 곱하고 더하는 과정 반복하기