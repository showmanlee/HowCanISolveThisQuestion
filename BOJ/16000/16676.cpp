// 근우의 다이어리 꾸미기
// https://www.acmicpc.net/problem/16676

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int res = 1;
    int p = 11;
    while (n >= p) {
        res++;
        p = p * 10 + 1;
    }
    cout << res << '\n';
}

// 0부터 n까지 표현하기 위해 필요한 0~9 세트 개수 구하기