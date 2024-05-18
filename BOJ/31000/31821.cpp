// 학식 사주기
// https://www.acmicpc.net/problem/31821

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
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int m;
    cin >> m;
    int res = 0;
    for (int i = 0; i < m; i++) {
        int p;
        cin >> p;
        res += v[p - 1];
    }
    cout << res << '\n';
}

// n가지 메뉴의 가격과 m명이 원하는 메뉴가 주어질 때, 총 가격 구하기