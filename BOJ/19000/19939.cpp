// 박 터뜨리기
// https://www.acmicpc.net/problem/19939

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   int n, k;
   cin >> n >> k;
   int p = 0, res = 0;
   for (int i = 1; i <= k; i++) {
      p += i;
   }
   if (n < p) {
      cout << -1 << '\n';
   } else {
      n -= p;
      if (n % k == 0) {
         cout << k - 1 << '\n';
      } else {
         cout << k << '\n';
      }
   }
}

// n개의 공을 k개의 바구니에 담는데 빈 바구니가 없어야 하고 바구니에 든 공의 수가 모두 달라야 할 떄, 가장 많이 담긴 바구니와 가장 적게 담긴 바구니의 최소 차 구하기(불가능하면 -1)

// 우선 공의 수가 1+2+...+k-1+k보다 작으면 조건에 맞게 분배할 수 없음
// 따라서 분배되는 형태는 기본적으로 1, 2, ..., k-1, k - 이렇게 분배하고 남은 공의 수로 판정한다
// 만약 남은 공의 수가 k로 나누어떨어지면 각 바구니에 같은 양의 공을 넣어주면 되므로 차는 k(+?) - 1(+?) = k - 1
// 그렇지 않다면 가장 많은 공을 가진 바구니부터 하나씩 넣어주면 최소 차를 유지할 수 있다 - k(+?+1) - 1(+?) = k