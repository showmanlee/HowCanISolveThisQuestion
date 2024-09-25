// 고양이는 많을수록 좋다
// https://www.acmicpc.net/problem/27961

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    long long n;
    cin >> n;
    if (n <= 1) {
        cout << n;
    } else {
        long long res = 1, p = 1;
        while (n > p) {
            res++;
            p *= 2;
        }
        cout << res;
    }
    cout << '\n';
}

// 고양이 1마리 생성, 현재 있는 수까지 복제 명령으로 고양이 n마리를 만드는 최소 횟수 구하기

// 2^x