// 욱 제
// https://www.acmicpc.net/problem/17356

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   int a, b;
   cin >> a >> b;
   double m = (b - a) / 400.0;
   double res = 1 / (1 + pow(10, m));
   cout << res << '\n';
}

// m = (b - a) / 400 일 때, 1 / 1 + 10^m 구하기

// 구하면 됩니다...