// Malvika is peculiar about color of balloons
// https://www.acmicpc.net/problem/30156

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int a = 0, b = 0;
        for (char c : s) {
            if (c == 'a') {
                a++;
            } else {
                b++;
            }
        }
        cout << min(a, b) << '\n';
    }
}

// a와 b로 구성된 문자열에서 더 적은 수의 문자 개수 구하기