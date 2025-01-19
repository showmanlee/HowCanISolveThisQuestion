// Счастье Мистера Бина
// https://www.acmicpc.net/problem/29163

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        if (p % 2 == 1) {
            a++;
        } else {
            b++;
        }
    }
    if (a < b) {
        cout << "Happy" << '\n';
    } else {
        cout << "Sad" << '\n';
    }
}

// n개의 자연수 중 홀수보다 짝수가 더 많은지 확인하기