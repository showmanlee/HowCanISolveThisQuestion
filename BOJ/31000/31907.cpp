// GIST 찍기
// https://www.acmicpc.net/problem/31907

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int x = 0; x < 3; x++) {
        for (int i = 0; i < n; i++) {
            for (int y = 0; y < 4; y++) {
                for (int j = 0; j < n; j++) {
                    char c = '.';
                    if (x == 0 && y == 0) {
                        c = 'G';
                    } else if (x == 1 && y == 1) {
                        c = 'I';
                    } else if (x == 2 && y == 2) {
                        c = 'S';
                    } else if (x == 1 && y == 3) {
                        c = 'T';
                    }
                    cout << c;
                }
            }
            cout << '\n';
        }
    }
}

// 문제에 주어진 대로 글자 찍기