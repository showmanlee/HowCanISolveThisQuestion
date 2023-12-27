// 민주주의
// https://www.acmicpc.net/problem/30999

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int res = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int p = 0;
        for (char c : s) {
            if (c == 'O') {
                p++;
            }
        }
        if (p > m / 2) {
            res++;
        }
    }
    cout << res << '\n';
}

// m명이 찬반 투표한 n개의 문항 중 과반수가 찬성한 문항의 개수 출력하기

// 세어주면 됩니다 - m은 홀수거든요