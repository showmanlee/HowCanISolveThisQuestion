// Another Cow Number Game
// https://www.acmicpc.net/problem/6190

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    long long n;
    cin >> n;
    int res = 0;
    while (n != 1) {
        if (n % 2 == 1) {
            n = n * 3 + 1;
        } else {
            n /= 2;
        }
        res++;
    }
    cout << res << '\n';
}

// 주어진 자연수를 짝수일 땐 n * 3 + 1, 홀수일 땐 n / 2를 반복해 최종적으로 1로 만들 때, 필요한 횟수 구하기