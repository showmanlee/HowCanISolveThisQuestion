// 비요뜨의 징검다리 건너기
// https://www.acmicpc.net/problem/18291

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
        int p = n - 2;
        if (n <= 2) {
            cout << 1 << '\n';
            continue;
        }
        n %= 1000000007;
        long long res = 1;
        long long base = 2;
        while (p) {
            if (p % 2 == 1) {
                res = (res * base) % 1000000007;
            }
            base = (base * base) % 1000000007;
            p /= 2;
        }
        cout << res << '\n';
    }
}

// 1차원 공간에서 1번 칸에서 n번 칸으로 이동할 때 1~n칸 이동해 정확히 n번 칸에 도착할 수 있는 경우의 수 구하기

// 경우의 수를 계산해보면 1 1 2 4 8... 즉 2^(n - 2)임
// 이걸 그대로 pow로 계산했다가 범위 오류가 생김 - 나머지 연산을 이용해 범위를 줄여주고 계산한다