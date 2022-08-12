// Tournament Selection
// https://www.acmicpc.net/problem/14038

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n = 0;
    for (int i = 0; i < 6; i++) {
        char c;
        cin >> c;
        if (c == 'W') {
            n++;
        }
    }
    n = (n + 1) / 2;
    if (n == 0) {
        n = -1;
    } else {
        n = 4 - n;
    }
    cout << n << '\n';
}

// 총 6전에서 5~6승하면 1그룹, 3~4승하면 2그룹, 1~2승하면 3그룹으로 가고 0승하면 탈락할 때, 판정하기

// 개수를 보고 적절히 계산하면 답을 낼 수 있음 - 아니면 조건문을 써도 되고