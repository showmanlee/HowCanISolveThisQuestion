// N-Queen
// https://www.acmicpc.net/problem/9663

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int board[16];
int res;

void func(int p) {
   if (p == n) {
      res++;
      return;
   }
   for (int i = 0; i < n; i++) {
      board[p] = i;
      bool fail = false;
      for (int j = 0; j < p; j++) {
         if (board[j] == board[p] || p - j == abs(board[p] - board[j])) {
            fail = true;
            break;
         }
      }
      if (!fail) {
         func(p + 1);
      }
   }
}

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   cin >> n;
   func(0);
   cout << res << '\n';
}

// n*n 체스판에서 n개의 퀸이 서로 공격하지 못하게 놓는 경우의 수는?

// 각각의 퀸이 서로 같은 선상(가로, 세로, 대각선)에 놓이면 안 됨
// 사실 주어진 시간이 10초이기 때문에 브루트포스로 풀 수 있음 - 다만 2차원의 모든 칸을 볼 필요는 없음
// 왜냐면 어차피 내가 들어간 열에는 다른 누구도 들어올 수 없기 때문 - 따라서 행과 대각선만 보면 됨
// 이를 이용해 배열을 2차원 bool이 아닌 1차원 int로 생성, 들어가는 수를 열로 생각해서 확인한다
// 그렇게 되면 배치 가능 판정을 확인하기 위해 보드 위에 같은 숫자가 있는지, 그리고 현재 보드의 위치와 숫자의 차가 같은 경우가 보드에 있는지를 보면 됨