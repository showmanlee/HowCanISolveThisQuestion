// 사과와 바나나 나눠주기
// https://www.acmicpc.net/problem/14914

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   int a, b;
   cin >> a >> b;
   for (int i = 1; i <= min(a, b); i++) {
      if (a % i == 0 && b % i == 0) {
         cout << i << ' ' << (a / i) << ' ' << (b / i) << '\n';
      }
   }
}

// 사과와 바나나의 수가 주어질 때, 사과와 바나나를 모두 남기지 않고 정확하게 나눌 수 있는 인원과 경우 구하기

// 1부터 사과와 바나나 중 작은 수까지 돌면서, 두 수가 모두 나누어떨어질 때 출력
// 인원수 순서대로 정렬하면 되니, 1부터 돌리면 됨