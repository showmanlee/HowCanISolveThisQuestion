// 양수 개수 세기
// https://www.acmicpc.net/problem/14909

#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   int res = 0;
   int n;
   while (cin >> n) {
      if (n > 0) {
         res++;
      }
   } 
   cout << res << '\n';
}

// 주어진 정수 중 양수 개수 세기

// 숫자 개수가 주어지지 않기 때문에 실시간으로 카운팅해야 함