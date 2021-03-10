// 나누기
// https://www.acmicpc.net/problem/1075

#include <iostream>
using namespace std;

int main(void) {
    int n, f;
    cin >> n >> f;
    int res = 0;
    int b = n / 100 * 100;
    for (int i = b; i < b + 100; i++) {
        if (i % f == 0) {
            res = i % 100;
            break;
        }
    }
    cout << (res / 10) << (res % 10) << '\n';
}

// n의 마지막 두자리를 바꿔 f로 나누어떨어지게 하는 방법 중 가장 작은 것은?
// 까짓거 100번 돌려보지 뭐