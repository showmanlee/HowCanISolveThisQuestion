// 내 선물을 받아줘 2
// https://www.acmicpc.net/problem/15886

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int res = 0;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == 'E' && s[i] == 'W') {
            res++;
        }
    }
    cout << res << '\n';
}

// 길이 n의 1차원 보드에서 각 칸마다 이동하는 방향이 주어질 때, 어디서 출발하든 반드시 밟게 되는 칸 수 구하기

// 'EW'로 붙는 경우 반드시 한 칸을 밟게 됨