// Forbidden Zero
// https://www.acmicpc.net/problem/15122

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    while (true) {
        n++;
        bool zero = false;
        int nn = n;
        while (nn > 0) {
            if (nn % 10 == 0) {
                zero = true;
                break;
            }
            nn /= 10;
        }
        if (!zero) {
            cout << n << '\n';
            break;
        }
    }
}

// 주어진 정수에서 0이 들어가지 않고 그 다음으로 큰 수 구하기