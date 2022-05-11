// 덧셈과 곱셈
// https://www.acmicpc.net/problem/14579

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   int a, b;
   cin >> a >> b;
   long long p = 0;
   for (int i = 0; i <= a - 1; i++) {
      p += i;
   }
   long long res = 1;
   for (int i = a; i <= b; i++) {
      p += i;
      res = (res * p) % 14579;
   }
   cout << res << '\n';
}

// a < b인 a, b가 주어질 때, (1+2+…+a) * (1+2+…+(a+1)) * … * (1+2+…+(b-1)) * (1+2+…+b) % 14579 구하기

// 1부터 a-1까지 더한 변수에다 a부터 b까지 차례대로 더하면서 곱해주고, 나머지 처리합니다