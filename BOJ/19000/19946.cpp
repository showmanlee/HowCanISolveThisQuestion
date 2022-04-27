// 2의 제곱수 계산하기
// https://www.acmicpc.net/problem/19946

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);
   
   unsigned long long n;
   cin >> n;
   for (int i = 64; i >= 1; i--) {
       if (n % 2 == 1) {
           cout << i << '\n';
           break;
       }
       n /= 2;
   }
}

// 2^64까지 2를 곱하는 과정 중 딱 한 번 *2-1 연산을 했을 때 그 시점 구하기

// unsigned long long에서 구할 수 있는 최대 값은 2^64 - 1 = 2진수에서 1이 64개
// 2의 제곱수의 경우 비트가 1000.... 이런 식으로 나오는데, 여기서 1을 빼면 11111...의 형태가 됨
// 여기서 2를 곱할 때마다 0이 뒤에 붙으므로, 이 원리를 이용해 (64 - 뒤에 붙은 0 수)가 원하는 결과인 걸 알 수 있음