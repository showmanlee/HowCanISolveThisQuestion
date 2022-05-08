// 오르막길
// https://www.acmicpc.net/problem/2846

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   int n;
   cin >> n;
   int a = 0, b = 0, t = 98765, res = 0;
   for (int i = 0; i < n; i++) {
      int p;
      cin >> p;
      if (p <= t) {
         a = p;
      }
      b = p;
      res = max(res, b - a);
      t = p;
   }
   cout << res << '\n';
}

// 연속으로 증가하는 부분배열의 최대-최소가 가장 큰 경우 구하기

// 오르막 시작/끝, 직전 수를 저장하는 변수를 둔다 - 그냥 배열을 둬도 됨
// 만약 이전 수가 지금 수보다 큰 경우 끝점만 갱신하고, 그렇지 않으면 시작점도 갱신하여 오르막을 초기화한다
// 그렇게 구한 시작점/끝점을 이용해 오르막 크기를 구해 결과값에 갱신한다