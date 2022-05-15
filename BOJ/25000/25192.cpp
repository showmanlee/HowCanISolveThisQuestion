// 인사성 밝은 곰곰이
// https://www.acmicpc.net/problem/25192

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   int n;
   cin >> n;
   map<string, int> board;
   int enter = 0;
   int res = 0;
   for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      if (s == "ENTER") {
         enter++;
      } else {
         board[s]++;
         if (board[s] <= enter) {
            res++;
         }
         board[s] = enter;
      }
   }
   cout << res << '\n';
}

// 모든 사람들이 채팅방에 새로운 사람이 들어왔을 때 첫 마디로 이모티콘을 쓸 때, 이모티콘이 사용된 횟수 구하기

// 새로운 사람이 들어오면(ENTER) 그 이후 닉네임이 처음으로 등장하는 경우 이모티콘 사용 - ENTER가 다시 들어오면 초기화
// map을 이용해 이모티콘을 쓴 횟수를 기록한다 - 언제나 ENTER 이하가 유지될 수 있도록
// ENTER가 들어오면 사람이 들어온 횟수를 누적시킨다
// 닉네임이 들어오면 이모티콘 사용 횟수를 ++한 뒤, 그 값이 들어온 횟수 이하라면 결과값++
// 이후 이모티콘 사용 횟수를 사람이 들어온 횟수로 맞춰 중복 사용을 체크한다