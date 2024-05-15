// Sequences
// https://www.acmicpc.net/problem/5101

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    while (true) {
        int n, m, k;
        cin >> n >> m >> k;
        if (n == 0 && m == 0 && k == 0) {
            break;
        }
        if ((k - n) % m != 0) {
            cout << "X\n";
        } else {
            int res = (k - n) / m;
            if (res < 0) {
                cout << "X\n";
            } else {
                cout << (res + 1) << '\n';
            }
        }
    }
}

// n부터 시작해 등차가 m인 등차수열에서 k가 몇 번째 항인지(아니면 들어가지 못하는지) 확인하기

// 음수항이 없음에 주의