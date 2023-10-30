// 피자는 나눌 수록 커지잖아요
// https://www.acmicpc.net/problem/17946

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int n;
        cin >> n;
        cout << 1 << '\n';
    }
}

// 피자를 n번 자른 후 1+2+...+n조각을 줘야 할 때, 최대로 남는 조각 구하기

// 평면에서 조각을 최대로 내도록 자르는 방법은 다른 직선들과 모두 교점이 생기도록 긋는 것 - 이 경우 새로운 조각이 n개 생긴다
// 그래서 조각을 계속 자르면 1 -> 2 -> 4 -> 7 -> 11... 즉 (n^2 + n + 2) / 2가 된다
// 그리고 줘야 하는 조각의 수는 (n^2 + n) / 2
// 이렇게 나온 공식을 계산하면 2 / 2만 남는다 - 결과적으로 언제나 내가 가지는 피자 조각 수는 1개라는 것