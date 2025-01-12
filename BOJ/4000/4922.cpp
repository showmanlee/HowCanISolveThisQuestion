// Walk Like an Egyptian
// https://www.acmicpc.net/problem/4922

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        int p = n * n - (n - 1);
        cout << n << " => " << p << '\n';
    }
}

// Walk Like an Egyptian 게임 보드의 변 길이가 주어질 때, 구하기