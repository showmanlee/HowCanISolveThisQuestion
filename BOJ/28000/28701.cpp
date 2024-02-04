// 세제곱의 합
// https://www.acmicpc.net/problem/28701

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a = n * (n + 1) / 2;
    int b = a * a;
    cout << a << '\n' << b << '\n' << b << '\n';
}

// 1부터 n까지의 합, 1부터 n까지의 합의 제곱, 1부터 n의 세제곱의 합 구하기

// 마지막 둘은 서로 같습니다