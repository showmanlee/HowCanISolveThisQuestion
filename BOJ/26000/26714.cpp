// Liczenie punktów
// https://www.acmicpc.net/problem/26714

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < 10; i++) {
        bool pass = true;
        for (int j = 0; j < n / 10; j++) {
            char c;
            cin >> c;
            if (c == 'N') {
                pass = false;
            }
        }
        if (pass) {
            res++;
        }
    }
    cout << res << '\n';
}

// n/10개 문항을 모두 맞춰야 하는 문제 10세트가 주어질 때, 모두 맞춘 문제 개수 출력하기