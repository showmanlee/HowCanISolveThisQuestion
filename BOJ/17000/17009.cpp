// Winning Score
// https://www.acmicpc.net/problem/17009

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a3, a2, a1, b3, b2, b1;
    cin >> a3 >> a2 >> a1 >> b3 >> b2 >> b1;
    int a = a3 * 3 + a2 * 2 + a1;
    int b = b3 * 3 + b2 * 2 + b1;
    if (a > b) {
        cout << "A\n";
    } else if (a < b) {
        cout << "B\n";
    } else {
        cout << "T\n";
    }
}

// 각 팀의 3/2/1점슛 횟수가 주어질 때, 승리 팀 구하기

// 계산해서 구하면 되지요