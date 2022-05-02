// 국회의원 선거
// https://www.acmicpc.net/problem/1417

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   int n;
   cin >> n;
   int me;
   cin >> me;
   if (n == 1) {
      cout << "0\n";
      return 0;
   }
   priority_queue<int> pq;
   for (int i = 0; i < n - 1; i++) {
      int p;
      cin >> p;
      pq.push(p);
   }
   int res = 0;
   while (pq.top() >= me) {
      int t = pq.top();
      pq.pop();
      t--;
      me++;
      pq.push(t);
      res++;
   }
   cout << res << '\n';
   return 0;
}

// 각 후보의 예상 득표 수가 주어졌을 때, 1번 후보가 당선되기 위해 회유해야 하는 유권자 수는?

// 다른 후보 득표 수 중 가장 큰 득표 수에서 한 장씩 빼온다 - 누구도 1번을 넘을 수 없을 때까지
// 이를 위해 우선순위 큐를 이용하여 가장 큰 수를 구해준다 - 구해서 1 빼고 다시 넣고, 내 득표수는 1 더하고