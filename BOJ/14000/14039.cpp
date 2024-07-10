// Magic Squares
// https://www.acmicpc.net/problem/14039

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<vector<int>> v(4, vector<int>(4));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> v[i][j];
        }
    }
    int sum = v[0][0] + v[0][1] + v[0][2] + v[0][3];
    bool res = true;
    for (int i = 0; i < 4; i++) {
        int p = v[i][0] + v[i][1] + v[i][2] + v[i][3];
        if (p != sum) {
            res = false;
            break;
        }
        p = v[0][i] + v[1][i] + v[2][i] + v[3][i];
        if (p != sum) {
            res = false;
            break;
        }
    }
    cout << (res ? "" : "not ") << "magic\n";
}

// 주어진 4x4 배열이 마방진인지 판정하기