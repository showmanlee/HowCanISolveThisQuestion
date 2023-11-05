// To and Fro
// https://www.acmicpc.net/problem/4246

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        string s;
        cin >> s;
        vector<vector<char>> v(s.length() / n, vector<char>(n));
        bool side = true;
        int idxx = 0, idxy = 0;
        for (char c : s) {
            v[idxx][idxy] = c;
            idxy += (side ? 1 : -1);
            if ((idxy == n && side) || (idxy == -1 && !side)) {
                side = !side;
                idxx++;
                idxy += (side ? 1 : -1);
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < v.size(); i++) {
                cout << v[i][j];
            }
        }
        cout << '\n';
    }
}

// n행 2차원 배열에 원래 문자열을 좌측 상단부터 세로로 채워넣은 걸 좌측 상단부터 가로로 지그재그로 차례로 나열하여 만든 문자열이 주어질 때, 원문 구하기

// 어떻게 만들어졌는지 파악하고 출력학;