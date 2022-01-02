// 노솔브 방지문제야!!
// https://www.acmicpc.net/problem/15917

#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        cout << ((p & (p - 1)) == 0) << '\n';
    }
}

// 주어진 자연수가 2의 거듭제곱 꼴로 나타나는가?

// 이를 판정할 수 있는 방법은 여러 가지가 있을 수 있음
// 1. 문제 힌트처럼 p & -p == p인 경우(2의 보수법 활용) - (8 % -8) = 1000 & 1000 = 1000 = 8
// 2. 여기처럼 p & (p - 1) == 0인 경우 - (8 & 7) = 1000 & 0111 = 0000 = 0
// 3. sqrt를 돌리면서 계속 정수 상태인지 확인하기 - 이 경우 부동소수점 정밀도 관련 처리가 필요함