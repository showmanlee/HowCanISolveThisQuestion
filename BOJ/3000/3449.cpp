// 해밍 거리
// https://www.acmicpc.net/problem/3449

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   int n;
   cin >> n;
   for (int t = 0; t < n; t++) {
      string a, b;
      cin >> a >> b;
      int res = 0;
      for (int i = 0; i < a.length(); i++) {
         if (a[i] != b[i]) {
            res++;
         }
      }
      cout << "Hamming distance is " << res << ".\n";
   }
}

// 길이가 같은 두 이진수의 다른 자릿수(해밍 거리) 구하기

// 문자열로 받아 같은 인덱스를 비교하면 된다는 거지