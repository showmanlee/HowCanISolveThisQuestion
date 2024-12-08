// 커플링 매치
// https://www.acmicpc.net/problem/31908

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    map<string, vector<string>> board;
    vector<string> index;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        if (b != "-") {
            board[b].push_back(a);
            if (board[b].size() == 1) {
                index.push_back(b);
            }
        }
    }
    int res = 0;
    for (string s : index) {
        if (board[s].size() == 2) {
            res++;
        }
    }
    cout << res << '\n';
    for (string s : index) {
        if (board[s].size() == 2) {
            cout << board[s][0] << ' ' << board[s][1] << '\n';
        }
    }
}

// 사람들의 이름과 끼고 있는 반지 종류가 주어질 때, 똑같은 반지 2개를 끼고 있는 사람들 구하기