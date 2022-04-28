// Speed fines are not fine!
// https://www.acmicpc.net/problem/6763

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   int a, b;
   cin >> a >> b;
   if (a >= b) {
       cout << "Congratulations, you are within the speed limit!\n";
   }
   else {
       if (b - a <= 20) {
           cout << "You are speeding and your fine is $100." << '\n';
       } else if (b - a <= 30) {
           cout << "You are speeding and your fine is $270." << '\n';
       } else {
           cout << "You are speeding and your fine is $500." << '\n';
       }
   }
}

// 제한 속도와 단속 속도를 보고 벌금 판정하기

// 문제에 나온 대로 판정하면 됩니다...