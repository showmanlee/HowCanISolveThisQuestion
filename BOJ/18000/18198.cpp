// Basketball One-on-One
// https://www.acmicpc.net/problem/18198

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int a = 0, b = 0;
    char prev = ' ';
    bool ten = false;
    for (char c : s) {
        if (prev == ' ') {
            prev = c;
        } else {
            int p = c - '0';
            if (prev == 'A') {
                a += p;
            } else {
                b += p;
            }
            if (a == 10 && b == 10) {
                ten = true;
            }
            if (ten) {
                if (a > b && a - b >= 2) {
                    cout << 'A';
                    break;
                } else if (a < b && b - a >= 2) {
                    cout << 'B';
                    break;
                }
            } else {
                if (a > b && a >= 11) {
                    cout << 'A';
                    break;
                } else if (a < b && b >= 11) {
                    cout << 'B';
                    break;
                }
            }
            prev = ' ';
        }
    }
    cout << '\n';
}

// 두 사람이 차례로 1~2점씩 넣는 게임에서 10대10 동점이 안 나오면 11점을 먼저 내면 승리, 동점이 나오면 2점차를 먼저 내면 승리일 때, 게임 결과 출력하기

// 조건에 맞춰서 점수 카운팅 후 출력