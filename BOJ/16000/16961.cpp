// 탭 vs 공백
// https://www.acmicpc.net/problem/16961

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   int n;
   cin >> n;
   vector<int> tab(367), space(367);
   int a = 0, b = 0, c = 0, d = 0, e = 0;
   for (int t = 0; t < n; t++) {
      char u;
      int x, y;
      cin >> u >> x >> y;
      for (int i = x; i <= y; i++) {
         if (u == 'T') {
            tab[i]++;
         }
         else {
            space[i]++;
         }
      }
      e = max(e, y - x + 1);
   }
   for (int i = 1; i <= 366; i++) {
      if (tab[i] > 0 || space[i] > 0) {
         a++;
         b = max(b, tab[i] + space[i]);
         if (tab[i] == space[i]) {
            c++;
            d = max(d, tab[i] + space[i]);
         }
      }
   }
   cout << a << '\n' << b << '\n' << c << '\n' << d << '\n' << e << '\n';
}

// 호텔 안에 같은 인원이 있어야만 싸우지 않는 탭파와 공백파가 모두 머무를 수 있는 호텔의 1년 투숙객 현황이 주어졌을 때 아래 구하기
// a. 투숙객이 1명 이상인 날의 수
// b. 가장 많은 투숙객이 있었던 날에 투숙한 사람의 수
// c. 싸움이 없는 날의 수
// d. 싸움이 없는 날 중 가장 많은 투숙객이 있었던 날에 투숙한 사람의 수
// e. 가장 오랜 시간 투숙한 사람이 투숙한 날의 수

// 각 파의 투숙 현황을 366칸 배열에 인원수로 기록한다
// 이후 배열을 돌면서 통합 투숙객이 1명 이상일 때 a, b를 갱신하고, 그 중에서 두 파의 투숙객이 같을 떄 c, d를 갱신한다
// e의 경우 저 배열을 볼 필요 없이 종료일 - 시작일 + 1의 최댓값을 출력