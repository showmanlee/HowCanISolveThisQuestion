// 과자 사기
// https://www.acmicpc.net/problem/17450

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   double sp, sw, np, nw, up, uw;
   cin >> sp >> sw >> np >> nw >> up >> uw;
   sp *= 10;
   sw *= 10;
   if (sp >= 5000) {
       sp -= 500;
   }
   np *= 10;
   nw *= 10;
   if (np >= 5000) {
       np -= 500;
   }
   up *= 10;
   uw *= 10;
   if (up >= 5000) {
       up -= 500;
   }
   double s = sw / sp;
   double n = nw / np;
   double u = uw / up;
   if (s > n && s > u) {
       cout << "S\n";
   }
   if (n > s && n > u) {
       cout << "N\n";
   }
   if (u > s && u > n) {
       cout << "U\n";
   }
}

// 5000원 이상 구입하면 500원이 할인되는 마트에서 무게와 가격이 다른 과자를 10봉지 구입할 때, 무게/가격이 가장 큰 과자는?

// 실제로 계산해보면 됩니다 - 한 봉지에 10을 곱한 뒤 할인까지 적용해야 함에 주의