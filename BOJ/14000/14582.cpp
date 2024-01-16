// 오늘도 졌다
// https://www.acmicpc.net/problem/14582

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<int> v(18);
    for (int i = 0; i < 9; i++) {
        cin >> v[i * 2];
    }
    for (int i = 0; i < 9; i++) {
        cin >> v[i * 2 + 1];
    }
    bool res = false;
    int a = 0, b = 0;
    for (int i = 0; i < 18; i++) {
        if (i % 2 == 0) {
            a += v[i];
            if (a > b) {
                res = true;
            }
        } else {
            b += v[i];
        }
    }
    cout << (res ? "Yes" : "No") << '\n';
}

// 야구 경기에서 어웨이 팀이 패배하는 점수 표가 주어질 때, 어웨이 팀이 이기고 있던 순간이 있는지 확인하기

// 이닝을 돌려보면서 어웨이 팀이 점수가 더 많은 순간이 있는지 확인해본다