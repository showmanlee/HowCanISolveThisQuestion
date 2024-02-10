// 빅데이터 vs 정보보호 vs 인공지능
// https://www.acmicpc.net/problem/30957

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string st;
    cin >> st;
    int b = 0, s = 0, a = 0;
    for (char c : st) {
        if (c == 'B') {
            b++;
        } else if (c == 'S') {
            s++;
        } else if (c == 'A') {
            a++;
        }
    }
    if (s == b && b == a) {
        cout << "SCU";
    } else {
        if (b >= s && b >= a) {
            cout << "B";
        }
        if (s >= b && s >= a) {
            cout << "S";
        }
        if (a >= s && a >= b) {
            cout << "A";
        }
    }
    cout << '\n';
}

// B, S, A 중 가장 많이 나온 알파벳(들) 출력하기 - 셋 다 똑같이 나오면 SCU 출력하기

// 출력해줍시다