// Vending Machine
// https://www.acmicpc.net/problem/17284

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int res = 5000;
    int p;
    while (cin >> p) {
        if (p == 1) {
            res -= 500;
        } else if (p == 2) {
            res -= 800;
        } else if (p == 3) {
            res -= 1000;
        }
    }
    cout << res << '\n';
}

// 500원, 800원, 1000원 음료 버튼이 차례로 있는 자판기에서 5000원을 넣고 버튼을 누를 때 남은 거스름돈 출력하기

// while cin으로 누른 버튼 보고 잔액에서 돈 빼기