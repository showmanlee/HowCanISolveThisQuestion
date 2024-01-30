// Holes
// https://www.acmicpc.net/problem/3578

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    if (n == 0) {
        cout << 1 << '\n';
    } else if (n == 1) {
        cout << 0 << '\n';
    } else if (n == 2) {
        cout << 8 << '\n';
    } else {
        cout << (n % 2 == 1 ? 4 : 8);
        for (int i = 1; i < (n + 1) / 2; i++) {
            cout << 8;
        }
        cout << '\n';
    }
}

// 정수를 써서 숫자로 n개의 구멍을 만들 때, 값이 최소인 수 출력하기

// 4690은 구멍 하나, 8은 두 개를 만든다
// 0개일 경우 가장 작은 1, 1개일 경우 0, 2개일 경우 8을 출력하고, 그 이상일 경우 홀수면 4, 짝수면 8을 앞에 붙이고 나머지 자리는 8로 모두 채운다